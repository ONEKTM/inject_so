# 可用于测试Android注入so 并且 熟悉ptrace注入so的基本过程

# 使用方法：
 0.ndk 编译
 1.adb push inject /data/local/tmp 
 2.adb push libbridge.so /data/local/tmp
 3.adb shell, 切到root后, cd /data/local/tmp后, 给 777权限  
 4.执行: /data/local/tmp/inject pid  /data/local/tmp/libbridge.so

# 注意:so路径一定要写绝对路径，否则容易出现dlopen后返回地址是0的问题 

# 如果成功：
 1.cat /proc/pid/maps |grep 注入so名字 , 可以看到效果
 2.logcat 查看日志, hook_entry方法执行, 日志打印

运行日志：

[main] target_pid:15115, libpath:/data/local/tmp/libbridge.so
[init_sdk_ver] ro.build.version.sdk: 19
[+] Injecting process: 15115
[get_module_path] module_path:/system/lib/libc.so
[+] get_remote_addr: local[0xb6f69000], remote[0x40032000]
[+] Remote mmap address: 0x40044c5d
[+] Calling mmap in target process, current pc=1074083644
[+] Target process returned from mmap, return value=77c09000, pc=0
[+] read data: 1111111111111111111111111111111
[+] local dlopen=0xb6fcdf31, dlsym=0xb6fcde81, dlclose=0xb6fcddfd, dlerror=0xb6fcddad
[get_module_path] module_path:/system/bin/linker
[+] get_remote_addr: local[0xb6fcd000], remote[0x40017000]
[get_module_path] module_path:/system/bin/linker
[+] get_remote_addr: local[0xb6fcd000], remote[0x40017000]
[get_module_path] module_path:/system/bin/linker
[+] get_remote_addr: local[0xb6fcd000], remote[0x40017000]
[get_module_path] module_path:/system/bin/linker
[+] get_remote_addr: local[0xb6fcd000], remote[0x40017000]
[+] Get imports: dlopen: 0x40017f31, dlsym: 0x40017e81, dlclose: 0x40017dfd, dlerror: 0x40017dad
library path = /data/local/tmp/libbridge.so, map_base = 0x77c09000
[+] Calling dlopen in target process, current pc=0
[+] Target process returned from dlopen, return value=7667e24c, pc=0
[+] Calling dlsym in target process, current pc=0
[+] Target process returned from dlsym, return value=77a36d41, pc=0
hook_entry_addr = 0x77a36d41
[+] Calling hook_entry in target process, current pc=0
[+] Target process returned from hook_entry, return value=0, pc=0
Press enter to dlclose and detach
