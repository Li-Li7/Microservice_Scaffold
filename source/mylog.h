/*
日志操作封装
    1、防止头文件重复包含
    2、包含头文件
    3、声明命名空间
    4、声明全局日志器
    5、声明日志配置结构体
    6、声明全局日志器初始化接口
    7、封装日志输出宏
*/

#pragma once

#include<spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include<spdlog/sinks/rotating_file_sink.h>
#include<spdlog/async.h>


namespace mylog
{
    extern std::shared_ptr<spdlog::logger> g_logger;
    struct log_settings
    {
        bool async;//是否异步输出
        int level;
        std::string format;//日志输出格式[%H:%M:%S] [%-7l]: %v
        std::string path;//日志文件路径
    };
    extern void init_logger(const log_settings& settings);
    //封装日志输出宏
    #define FMT_PREFIX std::string("[{}:{}]:")
    #define DBG(fmt,...) mylog::g_logger->debug(FMT_PREFIX+fmt,__FILE__,__LINE__,##__VA_ARGS__)
    #define INFO(fmt,...) mylog::g_logger->info(FMT_PREFIX+fmt,__FILE__,__LINE__,##__VA_ARGS__)
    #define WARN(fmt,...) mylog::g_logger->warn(FMT_PREFIX+fmt,__FILE__,__LINE__,##__VA_ARGS__)
    #define ERR(fmt,...) mylog::g_logger->error(FMT_PREFIX+fmt,__FILE__,__LINE__,##__VA_ARGS__)
    #define CRIT(fmt,...) mylog::g_logger->critical(FMT_PREFIX+fmt,__FILE__,__LINE__,##__VA_ARGS__)
}
