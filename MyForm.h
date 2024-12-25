#pragma once
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>

struct ScheduleItem {
	int endHour;
	int endMinute;
	std::string name;
};

namespace $safeprojectname$ {
	using namespace std;

	using namespace System;
	using namespace System::Globalization;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			// 
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ time;
	protected:

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ statusLesson;
	private: System::Windows::Forms::Label^ dayOfWeek;






	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->time = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->statusLesson = (gcnew System::Windows::Forms::Label());
			this->dayOfWeek = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// time
			// 
			this->time->AutoSize = true;
			this->time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->time->Location = System::Drawing::Point(98, 70);
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(62, 25);
			this->time->TabIndex = 0;
			this->time->Text = L"Дата";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// statusLesson
			// 
			this->statusLesson->AutoSize = true;
			this->statusLesson->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->statusLesson->Location = System::Drawing::Point(99, 132);
			this->statusLesson->Name = L"statusLesson";
			this->statusLesson->Size = System::Drawing::Size(72, 24);
			this->statusLesson->TabIndex = 1;
			this->statusLesson->Text = L"Статус";
			this->statusLesson->Click += gcnew System::EventHandler(this, &MyForm::statusLesson_Click);
			// 
			// dayOfWeek
			// 
			this->dayOfWeek->AutoSize = true;
			this->dayOfWeek->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dayOfWeek->Location = System::Drawing::Point(107, 35);
			this->dayOfWeek->Name = L"dayOfWeek";
			this->dayOfWeek->Size = System::Drawing::Size(141, 25);
			this->dayOfWeek->TabIndex = 2;
			this->dayOfWeek->Text = L"День недели";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->dayOfWeek);
			this->Controls->Add(this->statusLesson);
			this->Controls->Add(this->time);
			this->Name = L"MyForm";
			this->Text = L"Отображение текущей пары";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void LogicForNotLessonTime() {
		statusLesson->Text = "Внеучебное время";
		statusLesson->ForeColor = System::Drawing::Color::Blue;
	}
	private: void LogicForWeekDays() {
		System::DateTime date = DateTime::Now;

		int currentHour = date.Hour;
		int currentMinute = date.Minute;

		vector<ScheduleItem> schedule = {
			{9, 45, "I пара"},
			{9, 50, "Пятиминутка"},
			{10, 35, "I пара"},
			{10, 45, "Перемена"},
			{11, 30, "II пара"},
			{11, 35, "Пятиминутка"},
			{12, 20, "II пара"},
			{13, 0, "Перемена"},
			{13, 45, "III пара"},
			{13, 50, "Пятиминутка"},
			{14, 35, "III пара"},
			{14, 45, "Перемена"},
			{15, 30, "IV пара"},
			{15, 35, "Пятиминутка"},
			{16, 20, "IV пара"},
			{16, 30, "Перемена"},
			{17, 15, "V пара"},
			{17, 20, "Пятиминутка"},
			{18, 5, "V пара"},
			{18, 15, "Перемена"},
			{19, 15, "VI пара"},
			{19, 20, "Пятиминутка"},
			{20, 20, "VI пара"}
		};

		for (const auto& item : schedule) {
			int endTime = item.endHour * 100 + item.endMinute;
			int currTime = currentHour * 100 + currentMinute;

			if (endTime - currTime > 0) {
				statusLesson->Text = gcnew System::String(item.name.c_str());

				return;
			}
		}
	}
	private: void LogicForWeekendDays() {
		statusLesson->Text = "Выходной";
		statusLesson->ForeColor = System::Drawing::Color::Red;
	}
	private: String^ GetDaysOfWeek() {
		DateTime now = DateTime::Now;
		CultureInfo^ culture = gcnew System::Globalization::CultureInfo("ru-RU");
		String^ dayOfWeek = now.ToString("dddd", culture);

		return dayOfWeek;
	}
	private: void LoadData() {
		System::DateTime date = DateTime::Now;

		time->Text = DateTime::Now.ToString("HH:mm:ss");
		dayOfWeek->Text = this->GetDaysOfWeek();
		
		if (this->GetDaysOfWeek() == "суббота" || this->GetDaysOfWeek() == "воскресенье") {
			this->LogicForWeekendDays();

			return;
		};

		const int a = 2020;
		const int b = date.Hour;
		const int c = date.Minute;
		const int res = a - (b * 100 + c);

		if (2020 - (date.Hour * 100 + date.Minute) < 0 || 900 - (date.Hour * 100 + date.Minute) > 0) {
			this->LogicForNotLessonTime();

			return;
		};

		this->LogicForWeekDays();
	}	
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->LoadData();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		this->LoadData();
	}
	private: System::Void statusLesson_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
