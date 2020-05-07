#include <Ethernet.h> //이더넷쉴드
#include <SPI.h>      //서버와 통신하는 헤더파일
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};    //이더넷 쉴드의 MAC 주소
IPAddress ip(192, 168, 3, 40); //접속하기 위한 IP주소
EthernetServer server(80); //이더넷서버 포트(Web port)(웹페이지 로드를 위함)

String HTTP_reg; //서버에서 요구하는 값을 받는 문자변수.
boolean LED_status = 0; //0=LOW 1=HIGH
int led_pin = 9;

void setup() {
  pinMode(led_pin, OUTPUT);  //LED 출력모드 설정
  Ethernet.begin(mac, ip);   //이더넷 쉴드 장치 초기화
  Serial.begin(9600);
  server.begin();        //EthernetServer 초기화
}
void loop() {
  EthernetClient client = server.available(); //서버의 상태를 받음.
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read(); //클라이언트의 바이트를 얻어옴.
        HTTP_reg += c;
        if (c == '\n') {    //c에 데이터가 모두 도착했을때
          client.println("HTTP/1.1 200 OK");          //웹사이트를 알려주는 헤더파일1
          client.println("Content-Type : text/html"); //2
          client.println("Connection : close");       //3
          client.println(); //줄바꿈

          //이더넷쉴드(Web)서버 -> 클라이언트로 보내는 내용(send Webpage)(브라우져에 뿌려줄 실제 내용)
          client.println("<!DOCTYPE html>");
          client.println("<html lang='ko'>");
          client.println("<head>");
          client.println("<meta charset='utf-8'>");
          client.println("<title>아두이노 + 이더넷쉴드</title>");
          client.println("</head>");
          client.println("<body>");
          client.println("<h1>IOT홈에서 LED제어하기</h1>");
          client.println("<form method='get'>");
          processCheckBox(client);
          client.println("</form>");
          client.println("</body>");
          client.println("</html>");
          Serial.print(HTTP_reg); //클라이언트로 받는값을 출력
          HTTP_reg = "";
          break;
        }
      }
    }
    delay(1);
    client.stop();
  }
}
void processCheckBox(EthernetClient eclient) {
  if (HTTP_reg.indexOf("LED=1")>-1) { //HTTP_reg에 값이 들어오면 indexOf
    if (LED_status) {
      LED_status = 0;
    } else {
      LED_status = 1;
    }
  }
  if (LED_status) {
    digitalWrite(led_pin, HIGH);
    eclient.println("<input type='checkbox' name='LED' value='1' onclick='submit();' checked />LED전등");
  } else {
    digitalWrite(led_pin, LOW);
    eclient.println("<input type='checkbox' name='LED' value='1' onclick='submit();' />LED전등");
  }
}
