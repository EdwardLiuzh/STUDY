﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_MAINWINDOW
#define VCZH_WORKFLOW_COMPILER_GENERATED_MAINWINDOW

#include "DemoPartialClasses.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

namespace demo
{
	class MainWindow : public ::vl::presentation::controls::GuiWindow, public ::demo::MainWindowConstructor, public ::vl::reflection::Description<MainWindow>
	{
		friend class ::demo::MainWindowConstructor;
		friend class ::vl_workflow_global::__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__vl_reflection_description_IValueSubscription;
		friend struct ::vl_workflow_global::__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf2_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_;
		friend struct ::vl_workflow_global::__vwsno3_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MainWindow>;
#endif
	protected:
		::vl::vint integerState;
		void buttonPaste_Clicked(::vl::presentation::compositions::GuiGraphicsComposition* sender, ::vl::presentation::compositions::GuiEventArgs* arguments);
	public:
		MainWindow();
		~MainWindow();

	/* USER_CONTENT_BEGIN(custom members of ::demo::MainWindow) */
	/* USER_CONTENT_END() */
	};

}
#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif