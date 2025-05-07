#include "common.hpp"
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include <fcntl.h>
#include <iostream>
#include <net/if.h>
#include <sys/ioctl.h>
#include <array>
#include <unistd.h>
#include <iomanip>
#include "tuntap.hpp"

int main() {
    int fd = 0;
    std::string dev_name = "tun0";
    fd = tun_alloc(dev_name);
    if (fd < 0) {
        std::cout << "tun_alloc failed" << std::endl;
        return -1;
    }

    std::array<std::byte, 1504> buf;
    while (1) {
        int nbytes = read(fd, buf.data(), buf.size());
        if (nbytes < 0) {
            std::cout << "read failed" << std::endl;
            return -1;
        }
        std::cout << "read " << nbytes << " bytes" << std::endl;
        // hex print
        for (ssize_t i = 0; i < nbytes; ++i) {
            // use std::hex and std::setw to make sure echo format
            std::cout << std::hex << std::setw(2) << std::setfill('0') 
                        << static_cast<int>(buf[i]) << " ";
        }
        std::cout << "\n\n";
    }
    return 0;
}