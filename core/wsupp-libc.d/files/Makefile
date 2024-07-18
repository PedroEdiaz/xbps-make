all: libs wsupp wifi

libs: common.a crypto.a nlusctl.a netlink.a

WSUPP_OBJ=  \
	wsupp.o wsupp_netlink.o wsupp_eapol.o wsupp_crypto.o wsupp_cntrl.o \
	wsupp_slots.o wsupp_sta_ies.o wsupp_config.o wsupp_apsel.o \
	wsupp_rfkill.o wsupp_ifmon.o \
	common.a crypto.a nlusctl.a netlink.a 

WIFI_OBJ=  \
	wifi.o wifi_dump.o wifi_pass.o wifi_wire.o \
	common.a crypto.a nlusctl.a 

wsupp: $(WSUPP_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(WSUPP_OBJ)

wifi: $(WIFI_OBJ)
	$(CC) $(LDFLAGS) -o $@ $(WIFI_OBJ)

common.a:
	$(MAKE) -C common
	$(AR) cr $@ common/*.o

crypto.a:
	$(MAKE) -C crypto
	$(AR) cr $@ crypto/*.o

nlusctl.a:
	$(MAKE) -C nlusctl
	$(AR) cr $@ nlusctl/*.o

netlink.a:
	$(MAKE) -C netlink
	$(AR) cr $@ netlink/*.o

clean:
	rm -f *.a *.o */*.o
