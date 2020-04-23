import java.io.IOException;
import java.util.ArrayList;

import javax.websocket.OnClose;
import javax.websocket.OnError;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import javax.websocket.server.ServerEndpoint;

@ServerEndpoint("/websocket")
public class MyWebSocket
{
	@OnOpen
	public void onOpen(Session session)
	{
		System.out.println("[" + session.getId() + "] 클라이언트가 연결되었습니다.");	
		
		Client.addSession(session);
	}
	
	@OnMessage
	public void onMessage(Session session, String message)
	{
		Client.sendMessage("[" + session.getId() + "] : " + message);
	}
	
	@OnError
	public void onError(Session session, Throwable t)
	{
		Client.removeSession(session);
	}
	
	@OnClose
	public void onClose(Session session)
	{
		System.out.println("[" + session.getId() + "] 클라이언트와의 연결이 종료되었습니다.");
		Client.removeSession(session);
	}
}