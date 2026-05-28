#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, CONFIG_LOG_DEFAULT_LEVEL);

int main() {
    LOG_INF("Hello from %s", CONFIG_BOARD);
    return 0;
}
