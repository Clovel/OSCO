# OSCO - Open Source CANOpen stack
Open Source CANOpen stack by Clovel

**This project and it's dependecies are WIP !**

## Linked repositories
For now, the `OSCOCANDriver` uses [CAN over IP](https://github.com/Clovel/can-ip) as a CAN driver.
Here is the list of driver layers in development for the OSCO project : 
- [can-ip](https://github.com/Clovel/can-ip) : CAN over UDP boradcast
- [can-serial](https://github.com/Clovel/can-serial) : CAN over Serial, using CANUSB protocol
- [can-socketcan](https://github.com/Clovel/can-socketcan) : CAN over SocketCAN for Linux

To build a CAN transceiver for macOS, I am building an USB-to-ESP8266-to-MCP2515 device that will work with [can-serial](https://github.com/Clovel/can-serial). It is called the [esp-can-spi-bridge](https://github.com/Clovel/esp-can-spi-bridge)

A Object Dictionary code geenrator is being built at [OSCO-OD-Gen](https://github.com/Clovel/OSCO-OD-Gen).

To implement a clock for the examples, [TimerThread](https://github.com/Clovel/TimerThread).

To implement the INI file parser, this project uses [INITools](https://github.com/Clovel/initools).

## Contributing
Contributions are welcome !
Please refer to the [CONTRIBUTING.md](https://github.com/Clovel/OSCO/blob/master/CONTRIBUTING.md) for more information.

## Code of Conduct
A [code of conduct](https://github.com/Clovel/OSCO/blob/master/CODE_OF_CONDUCT.md) has been established. Please do your best to comply to it.
By following the rules, we ensure that our interractions will be as civil and enjoyable as possible.
