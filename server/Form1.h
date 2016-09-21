#pragma once
#using <System.Runtime.Remoting.dll>
#using <System.dll>
//#using <Remotable.dll>
namespace server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Timers;
	/// <summary>
	/// Form1 摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  shownow;
	private: System::Windows::Forms::TextBox^  state;
	private: System::Windows::Forms::TextBox^  txtIP;
	protected: 



	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  Interrupt;
	private: System::Windows::Forms::Button^  Rebinding;





	private:
		/// <summary>
		/// 必需的设计器变量。
		static NetworkStream^ stream=nullptr;/*网络数据流*/
		static array<Byte>^Rdata;/*信息接收缓冲区*/
		static array<Byte>^Wdata;//信息发送缓存区
		Thread ^trd;
	public: static String^ showdata="";
			static String^ Tstatc="";
			static bool IsInterrupt=false;
			static IPAddress^SIP;
			static Int32 port; 
			CreatServer^_server;
			static TcpListener^server=nullptr;/*服务器*/
			static TcpClient^ client=nullptr;//客户端对象
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtPort;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->shownow = (gcnew System::Windows::Forms::TextBox());
			this->state = (gcnew System::Windows::Forms::TextBox());
			this->txtIP = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Interrupt = (gcnew System::Windows::Forms::Button());
			this->Rebinding = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPort = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"实时动作信息";
			// 
			// shownow
			// 
			this->shownow->AcceptsReturn = true;
			this->shownow->AcceptsTab = true;
			this->shownow->AccessibleRole = System::Windows::Forms::AccessibleRole::ScrollBar;
			this->shownow->AllowDrop = true;
			this->shownow->Font = (gcnew System::Drawing::Font(L"方正舒体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->shownow->Location = System::Drawing::Point(142, 28);
			this->shownow->Margin = System::Windows::Forms::Padding(4);
			this->shownow->Multiline = true;
			this->shownow->Name = L"shownow";
			this->shownow->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->shownow->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->shownow->Size = System::Drawing::Size(463, 103);
			this->shownow->TabIndex = 1;
			// 
			// state
			// 
			this->state->Enabled = false;
			this->state->Font = (gcnew System::Drawing::Font(L"方正舒体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->state->Location = System::Drawing::Point(142, 160);
			this->state->Margin = System::Windows::Forms::Padding(4);
			this->state->Name = L"state";
			this->state->Size = System::Drawing::Size(148, 24);
			this->state->TabIndex = 2;
			// 
			// txtIP
			// 
			this->txtIP->Font = (gcnew System::Drawing::Font(L"方正舒体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->txtIP->Location = System::Drawing::Point(142, 219);
			this->txtIP->Margin = System::Windows::Forms::Padding(4);
			this->txtIP->Name = L"txtIP";
			this->txtIP->Size = System::Drawing::Size(319, 20);
			this->txtIP->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(54, 164);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"连接状态";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(54, 223);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"服务端IP";
			// 
			// Interrupt
			// 
			this->Interrupt->Location = System::Drawing::Point(57, 299);
			this->Interrupt->Margin = System::Windows::Forms::Padding(4);
			this->Interrupt->Name = L"Interrupt";
			this->Interrupt->Size = System::Drawing::Size(112, 45);
			this->Interrupt->TabIndex = 6;
			this->Interrupt->Text = L"断开连接";
			this->Interrupt->UseVisualStyleBackColor = true;
			this->Interrupt->Click += gcnew System::EventHandler(this, &Form1::Interrupt_Click);
			// 
			// Rebinding
			// 
			this->Rebinding->Location = System::Drawing::Point(406, 299);
			this->Rebinding->Margin = System::Windows::Forms::Padding(4);
			this->Rebinding->Name = L"Rebinding";
			this->Rebinding->Size = System::Drawing::Size(166, 44);
			this->Rebinding->TabIndex = 7;
			this->Rebinding->Text = L"断开重连";
			this->Rebinding->UseVisualStyleBackColor = true;
			this->Rebinding->Click += gcnew System::EventHandler(this, &Form1::Rebinding_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(362, 167);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(72, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"开放端口";
			// 
			// txtPort
			// 
			this->txtPort->BackColor = System::Drawing::SystemColors::Window;
			this->txtPort->Enabled = false;
			this->txtPort->Location = System::Drawing::Point(449, 164);
			this->txtPort->Name = L"txtPort";
			this->txtPort->Size = System::Drawing::Size(123, 24);
			this->txtPort->TabIndex = 9;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(652, 391);
			this->Controls->Add(this->txtPort);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Rebinding);
			this->Controls->Add(this->Interrupt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtIP);
			this->Controls->Add(this->state);
			this->Controls->Add(this->shownow);
			this->Controls->Add(this->label1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Font = (gcnew System::Drawing::Font(L"方正舒体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->ForeColor = System::Drawing::Color::Blue;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"server";
			this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {//窗体加载方法
				 try{
					 _CreatServer();
					 Windows::Forms::Timer^ShowTimer = gcnew Windows::Forms::Timer();
					 ShowTimer->Tick+=gcnew System::EventHandler(this, &server::Form1::OnTick);
					 ShowTimer->Interval = 500;
					 ShowTimer->Start();
					}
				 catch (SocketException^e)
				 {
					 MessageBox::Show(Convert::ToString(e));
				 }
			 }
	public: System::Void Interrupt_Click(System::Object^  sender, System::EventArgs^  e) {//中断连接方法
				
				try
				{
					_server->stopserver();
					shownow->Text = "";
					txtIP->Text = "";
					txtPort->Text = "";
					showdata = "";
				}
				catch (SocketException^e)
				{
					shownow->Text = Convert::ToString(e);
				}
	}
			 
private: System::Void Rebinding_Click(System::Object^  sender, System::EventArgs^  e) {//断开重连方法
			 RebindingFunc();

}
	private:  void _CreatServer()//建立服务器方法
	{
				 try{
					 _server=gcnew CreatServer(8080);
					 _server->creatserver();
					 txtPort->Text= Convert::ToString(_server->port);
					 showdata = "创建服务器\n";
					 Tstatc = "未连接";
					 txtIP->Text = _server->ServerChannel->GetChannelUri();
					 while (_server->EnumList->MoveNext())
					 { 
						 showdata = safe_cast<String^>(_server->EnumList->Current)+"\n";
						 shownow->AppendText(showdata);
					 }
					 showdata +="  "+"channel name is:"+ _server->ServerChannel->ChannelName;
					 _server->creatchannel(12581);
				  }
				  catch (SocketException^e)
				  {
					  shownow->Text = Convert::ToString(e);
					  MessageBox::Show(Convert::ToString(e));
				  }
	}
	private:void RebindingFunc()
	{
				try
				{
					_server->stopserver();
					shownow->Text = "";
					txtIP->Text = "";
					txtPort->Text = "";
					_CreatServer();
				}
				catch (SocketException^e)
				{
					shownow->Text = Convert::ToString(e);
				}
	}
private: static void  Interrupt_detection(IAsyncResult^ result)//连接存在检查方法
	{	
			 try{

			 }
			 catch (Exception^ e)
			 {
				

			 }
			
			
		 }
		 void OnTick(System::Object ^sender, System::EventArgs ^e)
		 {

			 if (shownow->Text!=showdata)
			 shownow->AppendText(showdata);
			 if (state->Text != Tstatc)
			 state->Text = Tstatc;
		 }
		
};
}




