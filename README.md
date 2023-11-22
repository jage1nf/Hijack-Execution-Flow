1.
Attack Commands:
sudo sh -c 'echo #{path_to_shared_library} > /etc/ld.so.preload'
Cleanup Commands:
sudo sed -i 's##{path_to_shared_library}##' /etc/ld.so.preload

2.
Attack Commands:
LD_PRELOAD=#{path_to_shared_library} ls
