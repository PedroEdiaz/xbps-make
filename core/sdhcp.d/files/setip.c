#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <net/if.h>
#include <net/route.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>

int main( void )
{
	struct sockaddr_in * addr;
	char *ifname = getenv( "IFNAME" ),
	     *client = getenv( "CLIENT" ),
	     *getway = getenv( "ROUTER" ),
	     *mask   = getenv( "MASK"   );

	int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);

	// IP
	{
		struct ifreq iface;
		iface.ifr_addr.sa_family = AF_INET;
		strcpy( iface.ifr_name, ifname );

		addr = &iface.ifr_addr;
	
		addr->sin_family = AF_INET;
		addr->sin_addr.s_addr = inet_addr(client);
		ioctl(fd, SIOCSIFADDR, &iface);

		addr->sin_family = AF_INET;
		addr->sin_addr.s_addr = inet_addr(mask);
		ioctl(fd, SIOCSIFNETMASK, &iface);

		iface.ifr_flags |= ( IFF_UP | IFF_RUNNING );
		ioctl(fd, SIOCSIFFLAGS, &iface);
	}	

	// ROUTE
	{
		struct rtentry route;

		addr = &route.rt_dst;
		addr->sin_family = AF_INET;
		addr->sin_addr.s_addr = INADDR_ANY;

		addr = &route.rt_gateway;
		addr->sin_family = AF_INET;
		addr->sin_addr.s_addr = inet_addr(getway);

		addr = &route.rt_genmask;
		addr->sin_family = AF_INET;
		addr->sin_addr.s_addr = INADDR_ANY;

		route.rt_flags = RTF_UP | RTF_GATEWAY ;
		ioctl(fd, SIOCADDRT, &route);
	}

	close(fd);
	return 0;
}
