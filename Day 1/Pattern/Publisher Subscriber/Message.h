#pragma once

enum class TMsgType
{
	kTestMsg
};

class Message
{
public:
	Message(TMsgType msgType)
		: m_msgType(msgType)
	{
	
	}
	virtual ~Message() {}
	inline TMsgType GetType() { return m_msgType;  }
protected:
	TMsgType m_msgType;
};