/*
 * Created by SharpDevelop.
 * User: Nurdan
 * Date: 6.12.2021
 * Time: 00:32
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;

namespace seriPortOdev2021
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		string gelenveri=string.Empty;
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		

		

		

		
	
		
		void Button1Click(object sender, EventArgs e)
		{
			if(!serialPort1.IsOpen)
			{
				serialPort1.PortName=textcom.Text;
				serialPort1.BaudRate=Convert.ToInt32(textBaudrate.Text);
				serialPort1.DataBits=Convert.ToInt32(textdatabit.Text);
				serialPort1.Open();
				
			}
			
		}
		
		void BtnkapatClick(object sender, EventArgs e)
		{
			if(serialPort1.IsOpen)
			{
				serialPort1.Close();
			}
		}
		
		void BtnGonderClick(object sender, EventArgs e)
		{
			Control.CheckForIllegalCrossThreadCalls = false;
			serialPort1.Write("#"+textGonderilecekVeriler.Text);
			
		}
		
		void SerialPort1DataReceived(object sender, SerialDataReceivedEventArgs e)
		{
			gelenveri=serialPort1.ReadLine();
			if(gelenveri[0]=='(')
			{
				Control.CheckForIllegalCrossThreadCalls = false;
				ADCverisi.Text=gelenveri.Substring(1,4);
			}
			else if(gelenveri[0]=='{')
			{
				Control.CheckForIllegalCrossThreadCalls = false;
				textkeyfiveri.Text=gelenveri.Substring(1,gelenveri.Length-2);
			}
		
			this.Invoke(new EventHandler(DisplayText));
		}
		private void DisplayText(object sender, EventArgs e)
		{
			textgelenveri.Text=gelenveri;
		}
		
		void BtnSaatGonderClick(object sender, EventArgs e)
		{
			serialPort1.Write("&"+textBaslangicSaati.Text+"/");
		}
		
	
		
		void BtnLCD2cisatirisilClick(object sender, EventArgs e)
		{
			serialPort1.Write("*");
		}
		

	}
}
