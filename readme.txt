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
