#include "tuntap.hpp"

int tun_alloc(std::string dev)
{
    struct ifreq ifr;
    int fd = -1;
    int err;
    char *dev_name = dev.data();

    if( (fd = open("/dev/net/tun", O_RDWR)) < 0 )
       return -1;

    memset(&ifr, 0, sizeof(ifr));

    /* Flags: IFF_TUN   - TUN device (no Ethernet headers)
     *        IFF_TAP   - TAP device
     *
     *        IFF_NO_PI - Do not provide packet information
     */
    ifr.ifr_flags = IFF_TUN;
    if( *dev_name )
         strlcpy(ifr.ifr_name, dev_name, IFNAMSIZ);

    if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ){
         close(fd);
         return err;
    }
    return fd;
}