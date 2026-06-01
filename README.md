# Zephyr RTOS - praticidade para que desenvolve software e hardware

```bash
git clone https://github.com/matheusmbar/events-iot-2026-zephyr
cd events-iot-2026-zephyr

virtualenv .venv
source .venv/bin/activate
pip install west
west init -l manifest
west update
west packages pip --install

west sdk install -t arm-zephyr-eabi

cd samples/shell
west build -b <board> .
west flash
```
