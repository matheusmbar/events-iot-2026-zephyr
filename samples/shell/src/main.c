#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

int main() {
  LOG_INF("Hello from %s", CONFIG_BOARD);
  return 0;
}
