#include "frm_main.h"

using namespace System;
using namespace System::Windows::Forms;


int main () {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	rtp1::frm_main mainForm;
	Application::Run(%mainForm);
}