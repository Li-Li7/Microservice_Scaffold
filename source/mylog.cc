#include"mylog.h"

namespace mylog
{
    std::shared_ptr<spdlog::logger> g_logger;
    void init_logger(const log_settings& settings)
    {
        if(settings.async==true)
        {
            if(settings.path=="stdout")
            {
                g_logger=spdlog::stdout_color_mt<spdlog::async_factory>("stdout_logger");
            }
            else
            {
                g_logger=spdlog::basic_logger_mt<spdlog::async_factory>("file_logger",settings.path);
            }
        }
        else
        {
            if(settings.path=="stdout")
            {
                g_logger=spdlog::stdout_color_mt("stdout_logger");
            }
            else
            {
                g_logger=spdlog::basic_logger_mt("file_logger",settings.path);
            }
        }
        g_logger->set_level(spdlog::level::level_enum(settings.level));
        g_logger->set_pattern(settings.format);
    }
}