#using <System.Runtime.Remoting.dll>
#using <System.dll>

using namespace System;
using namespace System::Runtime;
using namespace System::Runtime::Remoting;
using namespace System::Runtime::Remoting::Channels;
using namespace System::Runtime::Remoting::Channels::Tcp;
using namespace System::Security::Permissions;
namespace server {

	public ref class CreatServer
	{
	public:
		int port;
		TcpServerChannel^ ServerChannel;
		TcpChannel^Channel;
		System::Collections::IEnumerator^EnumList;
		CreatServer(int Cport)
		{
			port = Cport;
		}
		int creatserver()
		{
			ServerChannel = gcnew TcpServerChannel(port);//创建服务端信道
			ChannelServices::RegisterChannel(ServerChannel);//注册信道
			Remote^ remote = gcnew Remote();
			RemotingConfiguration::RegisterWellKnownServiceType(Remote::typeid, "remote", WellKnownObjectMode::Singleton);
			ChannelDataStore^Data = dynamic_cast<ChannelDataStore^>(ServerChannel->ChannelData);//储存远程处理信道的信道数据
			 EnumList= Data->ChannelUris->GetEnumerator();//?
			return 0;
		}
		int creatchannel(int port)
		{
			Channel = gcnew TcpChannel(port);
			return 0;
		}
		int DataRecall()
		{	
			System::Type^DataR;
			Remote^Recall = gcnew Remote();
			Recall->CreateObjRef(DataR);
			
			return 0;
		}
		int stopserver()
		{
			if (ServerChannel != nullptr)
			ServerChannel->StopListening(this->Channel);
			return 0;
		}
	private:
		ref class Remote : public MarshalByRefObject{};

	};
}