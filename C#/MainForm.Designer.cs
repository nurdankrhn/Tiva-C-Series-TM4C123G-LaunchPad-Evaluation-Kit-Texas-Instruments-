/*
 * Created by SharpDevelop.
 * User:   Nurdan
 * Date: 6.12.2021
 * Time: 00:32
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace seriPortOdev2021
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.btnac = new System.Windows.Forms.Button();
			this.btnkapat = new System.Windows.Forms.Button();
			this.textcom = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.textBaudrate = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.textdatabit = new System.Windows.Forms.TextBox();
			this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
			this.label4 = new System.Windows.Forms.Label();
			this.textGonderilecekVeriler = new System.Windows.Forms.TextBox();
			this.btnGonder = new System.Windows.Forms.Button();
			this.label5 = new System.Windows.Forms.Label();
			this.textgelenveri = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.ADCverisi = new System.Windows.Forms.TextBox();
			this.label7 = new System.Windows.Forms.Label();
			this.textBaslangicSaati = new System.Windows.Forms.TextBox();
			this.btnSaatGonder = new System.Windows.Forms.Button();
			this.btnLCD2cisatirisil = new System.Windows.Forms.Button();
			this.textkeyfiveri = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// btnac
			// 
			this.btnac.Location = new System.Drawing.Point(308, 34);
			this.btnac.Name = "btnac";
			this.btnac.Size = new System.Drawing.Size(75, 30);
			this.btnac.TabIndex = 0;
			this.btnac.Text = "AÇ";
			this.btnac.UseVisualStyleBackColor = true;
			this.btnac.Click += new System.EventHandler(this.Button1Click);
			// 
			// btnkapat
			// 
			this.btnkapat.Location = new System.Drawing.Point(308, 87);
			this.btnkapat.Name = "btnkapat";
			this.btnkapat.Size = new System.Drawing.Size(75, 32);
			this.btnkapat.TabIndex = 1;
			this.btnkapat.Text = "KAPAT ";
			this.btnkapat.UseVisualStyleBackColor = true;
			this.btnkapat.Click += new System.EventHandler(this.BtnkapatClick);
			// 
			// textcom
			// 
			this.textcom.Location = new System.Drawing.Point(164, 34);
			this.textcom.Name = "textcom";
			this.textcom.Size = new System.Drawing.Size(100, 22);
			this.textcom.TabIndex = 2;
			this.textcom.Text = "COM3";
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(33, 34);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(100, 23);
			this.label1.TabIndex = 3;
			this.label1.Text = "com no";
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(33, 96);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(100, 23);
			this.label2.TabIndex = 4;
			this.label2.Text = "Baudrate";
			// 
			// textBaudrate
			// 
			this.textBaudrate.Location = new System.Drawing.Point(164, 87);
			this.textBaudrate.Name = "textBaudrate";
			this.textBaudrate.Size = new System.Drawing.Size(100, 22);
			this.textBaudrate.TabIndex = 5;
			this.textBaudrate.Text = "115200";
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(33, 138);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(100, 23);
			this.label3.TabIndex = 6;
			this.label3.Text = "Databits";
			// 
			// textdatabit
			// 
			this.textdatabit.Location = new System.Drawing.Point(164, 135);
			this.textdatabit.Name = "textdatabit";
			this.textdatabit.Size = new System.Drawing.Size(100, 22);
			this.textdatabit.TabIndex = 7;
			this.textdatabit.Text = "8";
			// 
			// serialPort1
			// 
			this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPort1DataReceived);
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(33, 184);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(125, 32);
			this.label4.TabIndex = 8;
			this.label4.Text = "gonderilecek veri";
			// 
			// textGonderilecekVeriler
			// 
			this.textGonderilecekVeriler.Location = new System.Drawing.Point(164, 181);
			this.textGonderilecekVeriler.Multiline = true;
			this.textGonderilecekVeriler.Name = "textGonderilecekVeriler";
			this.textGonderilecekVeriler.Size = new System.Drawing.Size(150, 56);
			this.textGonderilecekVeriler.TabIndex = 9;
			this.textGonderilecekVeriler.Text = "lcdnin 2. satirinda gozukucek";
			// 
			// btnGonder
			// 
			this.btnGonder.Location = new System.Drawing.Point(320, 184);
			this.btnGonder.Name = "btnGonder";
			this.btnGonder.Size = new System.Drawing.Size(75, 44);
			this.btnGonder.TabIndex = 10;
			this.btnGonder.Text = "mc ye gonder";
			this.btnGonder.UseVisualStyleBackColor = true;
			this.btnGonder.Click += new System.EventHandler(this.BtnGonderClick);
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(33, 251);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(100, 23);
			this.label5.TabIndex = 11;
			this.label5.Text = "gelenveri";
			// 
			// textgelenveri
			// 
			this.textgelenveri.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
			this.textgelenveri.ForeColor = System.Drawing.SystemColors.Window;
			this.textgelenveri.Location = new System.Drawing.Point(139, 251);
			this.textgelenveri.Multiline = true;
			this.textgelenveri.Name = "textgelenveri";
			this.textgelenveri.Size = new System.Drawing.Size(219, 74);
			this.textgelenveri.TabIndex = 12;
			this.textgelenveri.Text = "Merhaba Yazisi Burada";
			// 
			// label6
			// 
			this.label6.Location = new System.Drawing.Point(33, 363);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(100, 23);
			this.label6.TabIndex = 13;
			this.label6.Text = "adc Verisi";
			// 
			// ADCverisi
			// 
			this.ADCverisi.Location = new System.Drawing.Point(188, 363);
			this.ADCverisi.Name = "ADCverisi";
			this.ADCverisi.Size = new System.Drawing.Size(126, 22);
			this.ADCverisi.TabIndex = 14;
			// 
			// label7
			// 
			this.label7.Location = new System.Drawing.Point(33, 406);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(106, 23);
			this.label7.TabIndex = 15;
			this.label7.Text = "baslangic saati";
			// 
			// textBaslangicSaati
			// 
			this.textBaslangicSaati.Location = new System.Drawing.Point(188, 403);
			this.textBaslangicSaati.Name = "textBaslangicSaati";
			this.textBaslangicSaati.Size = new System.Drawing.Size(126, 22);
			this.textBaslangicSaati.TabIndex = 16;
			this.textBaslangicSaati.Text = "12:34:56";
			// 
			// btnSaatGonder
			// 
			this.btnSaatGonder.Location = new System.Drawing.Point(332, 403);
			this.btnSaatGonder.Name = "btnSaatGonder";
			this.btnSaatGonder.Size = new System.Drawing.Size(97, 23);
			this.btnSaatGonder.TabIndex = 17;
			this.btnSaatGonder.Text = "Saat Gonder";
			this.btnSaatGonder.UseVisualStyleBackColor = true;
			this.btnSaatGonder.Click += new System.EventHandler(this.BtnSaatGonderClick);
			// 
			// btnLCD2cisatirisil
			// 
			this.btnLCD2cisatirisil.Location = new System.Drawing.Point(332, 441);
			this.btnLCD2cisatirisil.Name = "btnLCD2cisatirisil";
			this.btnLCD2cisatirisil.Size = new System.Drawing.Size(97, 48);
			this.btnLCD2cisatirisil.TabIndex = 18;
			this.btnLCD2cisatirisil.Text = "LCD satir 2 sil";
			this.btnLCD2cisatirisil.UseVisualStyleBackColor = true;
			this.btnLCD2cisatirisil.Click += new System.EventHandler(this.BtnLCD2cisatirisilClick);
			// 
			// textkeyfiveri
			// 
			this.textkeyfiveri.Location = new System.Drawing.Point(119, 335);
			this.textkeyfiveri.Name = "textkeyfiveri";
			this.textkeyfiveri.Size = new System.Drawing.Size(276, 22);
			this.textkeyfiveri.TabIndex = 19;
			this.textkeyfiveri.Text = "keyfiveri";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(477, 501);
			this.Controls.Add(this.textkeyfiveri);
			this.Controls.Add(this.btnLCD2cisatirisil);
			this.Controls.Add(this.btnSaatGonder);
			this.Controls.Add(this.textBaslangicSaati);
			this.Controls.Add(this.label7);
			this.Controls.Add(this.ADCverisi);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.textgelenveri);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.btnGonder);
			this.Controls.Add(this.textGonderilecekVeriler);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.textdatabit);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.textBaudrate);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.textcom);
			this.Controls.Add(this.btnkapat);
			this.Controls.Add(this.btnac);
			this.Name = "MainForm";
			this.Text = "seriPortOdev2021";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.TextBox textkeyfiveri;
		private System.Windows.Forms.Button btnLCD2cisatirisil;
		private System.Windows.Forms.Button btnSaatGonder;
		private System.Windows.Forms.TextBox textBaslangicSaati;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.TextBox ADCverisi;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.TextBox textgelenveri;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.Button btnGonder;
		private System.Windows.Forms.TextBox textGonderilecekVeriler;
		private System.Windows.Forms.Label label4;
		private System.IO.Ports.SerialPort serialPort1;
		private System.Windows.Forms.TextBox textdatabit;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox textBaudrate;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox textcom;
		private System.Windows.Forms.Button btnkapat;
		private System.Windows.Forms.Button btnac;
	}
}
