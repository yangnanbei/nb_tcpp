#include "common.hpp"
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <net/if.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "tuntap.hpp"

int main() {
    int fd = 0;
    std::string dev_name = "tun0";
    fd = tun_alloc(dev_name);
    if (fd < 0) {
        std::cout << "tun_alloc failed" << std::endl;
        return -1;
    }
    return 0;
}