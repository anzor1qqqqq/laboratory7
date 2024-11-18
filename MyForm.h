#pragma once
#include <string>
#include <vector>

struct ScheduleItem {
	int startHour;
	int startMinute;
	int endHour;
	int endMinute;
	std::string name;
};

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;

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
			this->Text = L"MyForm";
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

		//напиши логиу здесь
	}
	private: void LogicForWeekendDays() {
		statusLesson->Text = "Выходной";
		statusLesson->ForeColor = System::Drawing::Color::Red;
	}
	private: String^ GetDaysOfWeek() {
		String^ week;

		switch (DateTime::Now.DayOfWeek) {
			case DayOfWeek::Monday: week = "понедельник"; break;
			case DayOfWeek::Tuesday: week = "вторник"; break;
			case DayOfWeek::Wednesday: week = "среда"; break;
			case DayOfWeek::Thursday: week = "четверг"; break;
			case DayOfWeek::Friday: week = "пятница"; break;
			case DayOfWeek::Saturday: week = "суббота"; break;
			case DayOfWeek::Sunday: week = "воскресенье"; break;
		}

		return week;
	}

	private: void DisplayStatusInfo(String^ status) {
		statusLesson->Text = status;
	}
	private: void LoadData() {
		System::DateTime date = DateTime::Now;

		time->Text = DateTime::Now.ToString("HH:mm:ss");
		dayOfWeek->Text = this->GetDaysOfWeek();

		if (this->GetDaysOfWeek() == "суббота" || this->GetDaysOfWeek() == "воскресенье") {
			this->LogicForWeekendDays();

			return;
		};

		if (date.Hour >= 20 || date.Hour < 9) {
			if (date.Hour == 20 && date.Minute >= 20) {
				this->LogicForNotLessonTime();

				return;
			}

			this->LogicForNotLessonTime();

			return;
		}

		int currentHour = date.Hour;
		int currentMinute = date.Minute;

		std::vector<ScheduleItem> schedule = {
			{9, 0, 9, 45, "I пара"},
			{9, 45, 9, 50, "Пятиминутка"},
			{9, 50, 10, 35, "I пара"},
			{10, 35, 10, 45, "Перемена"},
			{10, 45, 11, 30, "II пара"},
			{11, 30, 11, 35, "Пятиминутка"},
			{11, 35, 12, 20, "II пара"},
			{12, 20, 13, 0, "Перемена"},
			{13, 0, 13, 45, "III пара"},
			{13, 45, 13, 50, "Пятиминутка"},
			{13, 50, 14, 35, "III пара"},
			{14, 35, 14, 45, "Перемена"},
			{14, 45, 15, 30, "IV пара"},
			{15, 30, 15, 35, "Пятиминутка"},
			{15, 35, 16, 20, "IV пара"},
			{16, 20, 16, 30, "Перемена"},
			{16, 30, 17, 15, "V пара"},
			{17, 15, 17, 20, "Пятиминутка"},
			{17, 20, 18, 5, "V пара"},
			{18, 5, 18, 15, "Перемена"},
			{18, 15, 19, 15, "VI пара"},
			{19, 15, 19, 20, "Пятиминутка"},
			{19, 20, 20, 20, "VI пара"}
		};

		for (const auto& item : schedule) {
			string start = to_string(item.startHour) + to_string(item.startMinute);
			string end = to_string(item.endHour) + to_string(item.endMinute);

			string currrent = to_string(currentHour) + to_string(currentMinute);

			if (stoi(start) - stoi(currrent) > 0) {
				this->DisplayStatusInfo(gcnew System::String(item.name.c_str()));
				return;
			}

			if (stoi(end) - stoi(currrent) > 0) {
				this->DisplayStatusInfo(gcnew System::String(item.name.c_str()));
				return;
			}
		}

		return;
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
