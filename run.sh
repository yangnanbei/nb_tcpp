#!/bin/bash
cd build
make
ext=$?
if [[ $ext -ne 0 ]]; then
	exit $ext
fi

cd ..
sudo setcap cap_net_admin=eip ./build/nb_tcp_app
sudo ./build/nb_tcp_app &
pid=$!

echo "now if up tun0"
sudo ip addr add 192.168.0.1/24 dev tun0
sudo ip link set up dev tun0
trap "kill $pid" INT TERM
wait $pid
