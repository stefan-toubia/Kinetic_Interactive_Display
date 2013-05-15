
unsigned long last_received_time;

enum SERIAL_COMMANDS {
  DEPTH = 'D', 
  RED = 'R',
  GREEN = 'G',
  BLUE = 'B'
};

enum PACKET_FORMAT{
  HEADER_LOC = 0
};

struct {
  int buffer[RX_BUFFER_SIZE];
  int index;
}data_packet;
