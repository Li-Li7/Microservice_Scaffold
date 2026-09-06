#include<mylog.h>
#include<gflags/gflags.h>

//通过gflags定义捕获参数
DEFINE_bool(log_async,true,"是否启用异步日志");
DEFINE_int32(log_level,1,"日志输出等级,1:debug,2:info,3:warn,4:error,5:critical,6:off");
DEFINE_string(log_format,"[%H:%M:%S] [%-7l]%v","日志输出格式");
DEFINE_string(log_path,"stdout","日志文件路径");

int main(int argc,char* argv[])
{
    google::ParseCommandLineFlags(&argc,&argv,true);
    mylog::log_settings settings={
        .async=FLAGS_log_async,
        .level=FLAGS_log_level,
        .format=FLAGS_log_format,
        .path=FLAGS_log_path,
    };
    mylog::init_logger(settings);
    DBG("{}今年{}岁","张三",18);
    INFO("{}今年{}岁","李四",20);
    WARN("{}今年{}岁","王五",22);
    ERR("{}今年{}岁","赵六",24);
    CRIT("{}今年{}岁","王二",26);
    DBG("hello");
    return 0;
}