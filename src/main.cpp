#include "common.hpp"

int main() {
    int tun_fd = open("/dev/net/tun", O_RDWR);
    if (tun_fd == -1) {
        perror("Opening /dev/net/tun");
        exit(1);
    }
    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = IFF_TUN | IFF_NO_PI; // Use IFF_TAP for TAP interfaces

    // Specify the interface name
    strncpy(ifr.ifr_name, "tun0", IFNAMSIZ);
    if (ioctl(tun_fd, TUNSETIFF, &ifr) == -1) {
        perror("Creating TUN interface");
        close(tun_fd);
        exit(1);
    }
}