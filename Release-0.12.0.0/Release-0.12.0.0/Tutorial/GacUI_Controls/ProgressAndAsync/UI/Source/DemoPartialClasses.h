﻿/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

GacGen.exe Resource.xml

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_DEMOPARTIALCLASSES
#define VCZH_WORKFLOW_COMPILER_GENERATED_DEMOPARTIALCLASSES

#include "GacUI.h"

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

namespace vl_workflow_global
{
	struct __vwsnf1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_;
	struct __vwsnf2_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__;
	struct __vwsnf3_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___;
	struct __vwsnf4_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__;
	struct __vwsnf5_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___;
	struct __vwsnf6_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____;
	struct __vwsnf7_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume_;
	struct __vwsnf8_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume__;
	struct __vwsnf9_Demo_demo_IViewModel_DownloadAsync_;
	class __vwsnc1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____vl_reflection_description_ICoroutine;
	class __vwsnc2_Demo_demo_IViewModel_DownloadAsync__demo_IStringAsync;
}

namespace demo
{
	class IStringAsync;
	class IViewModel;
	class MainWindowConstructor;
	class MainWindow;

	class IStringAsync : public virtual ::vl::reflection::description::IAsync, public ::vl::reflection::Description<IStringAsync>
	{
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IStringAsync>;
#endif
	public:
		static ::vl::WString CastResult(const ::vl::reflection::description::Value& value);
		static ::vl::reflection::description::Value StoreResult(const ::vl::WString& value);
	};

	class IViewModel : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<IViewModel>
	{
		friend class ::vl_workflow_global::__vwsnc2_Demo_demo_IViewModel_DownloadAsync__demo_IStringAsync;
		friend struct ::vl_workflow_global::__vwsnf9_Demo_demo_IViewModel_DownloadAsync_;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<IViewModel>;
#endif
	public:
		virtual void BeginDownload(const ::vl::Func<void(::vl::vint)>& progress, const ::vl::Func<void(const ::vl::WString&)>& callback) = 0;
		static ::vl::Ptr<::demo::IStringAsync> DownloadAsync(::vl::Ptr<::demo::IViewModel> viewModel, const ::vl::Func<void(::vl::vint)>& progress);
	};

	class MainWindowConstructor : public ::vl::Object, public ::vl::reflection::Description<MainWindowConstructor>
	{
		friend class ::vl_workflow_global::__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____vl_reflection_description_ICoroutine;
		friend struct ::vl_workflow_global::__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf2_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__;
		friend struct ::vl_workflow_global::__vwsnf3_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___;
		friend struct ::vl_workflow_global::__vwsnf4_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__;
		friend struct ::vl_workflow_global::__vwsnf5_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___;
		friend struct ::vl_workflow_global::__vwsnf6_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____;
		friend struct ::vl_workflow_global::__vwsnf7_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume_;
		friend struct ::vl_workflow_global::__vwsnf8_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume__;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MainWindowConstructor>;
#endif
	protected:
		::vl::Ptr<::demo::IViewModel> ViewModel;
		::demo::MainWindow* self;
		::vl::presentation::controls::GuiScroll* progressBar;
		::vl::presentation::controls::GuiButton* buttonDownload;
		::vl::presentation::controls::GuiMultilineTextBox* textResult;
		::vl::presentation::compositions::GuiTableComposition* __vwsn_precompile_0;
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_1;
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_2;
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_3;
		::vl::presentation::compositions::GuiCellComposition* __vwsn_precompile_4;
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_5;
		::vl::presentation::compositions::GuiBoundsComposition* __vwsn_precompile_6;
		void __vwsn_demo_MainWindow_Initialize(::demo::MainWindow* __vwsn_this_);
	public:
		MainWindowConstructor();
	};

	class MainWindow : public ::vl::presentation::controls::GuiWindow, public ::demo::MainWindowConstructor, public ::vl::reflection::Description<MainWindow>
	{
		friend class ::demo::MainWindowConstructor;
		friend class ::vl_workflow_global::__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____vl_reflection_description_ICoroutine;
		friend struct ::vl_workflow_global::__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_;
		friend struct ::vl_workflow_global::__vwsnf2_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__;
		friend struct ::vl_workflow_global::__vwsnf3_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___;
		friend struct ::vl_workflow_global::__vwsnf4_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__;
		friend struct ::vl_workflow_global::__vwsnf5_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___;
		friend struct ::vl_workflow_global::__vwsnf6_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____;
		friend struct ::vl_workflow_global::__vwsnf7_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume_;
		friend struct ::vl_workflow_global::__vwsnf8_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume__;
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<MainWindow>;
#endif
	public:
		::vl::Ptr<::demo::IViewModel> __vwsn_parameter_ViewModel;
		::vl::Ptr<::demo::IViewModel> GetViewModel();
		MainWindow(::vl::Ptr<::demo::IViewModel> __vwsn_ctor_parameter_ViewModel);
		~MainWindow();
	};

}
/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class Demo
	{
	public:

		static Demo& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_
	{
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize_(::demo::MainWindowConstructor* __vwsnctorthis_0);

		void operator()(::vl::presentation::compositions::GuiGraphicsComposition* sender, ::vl::presentation::compositions::GuiEventArgs* arguments) const;
	};

	struct __vwsnf2_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__
	{
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf2_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__(::demo::MainWindowConstructor* __vwsnctorthis_0);

		void operator()(::vl::vint progress) const;
	};

	struct __vwsnf3_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___
	{
		::vl::vint progress;
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf3_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___(::vl::vint __vwsnctor_progress, ::demo::MainWindowConstructor* __vwsnctorthis_0);

		void operator()() const;
	};

	struct __vwsnf4_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__
	{
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf4_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize__(::demo::MainWindowConstructor* __vwsnctorthis_0);

		::vl::Ptr<::vl::reflection::description::ICoroutine> operator()(::vl::reflection::description::AsyncCoroutine::IImpl* __vwsn_co_impl_) const;
	};

	struct __vwsnf5_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___
	{
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf5_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___(::demo::MainWindowConstructor* __vwsnctorthis_0);

		void operator()(::vl::vint progress) const;
	};

	struct __vwsnf6_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____
	{
		::vl::vint progress;
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnf6_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____(::vl::vint __vwsnctor_progress, ::demo::MainWindowConstructor* __vwsnctorthis_0);

		void operator()() const;
	};

	struct __vwsnf7_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume_
	{
		::vl::reflection::description::ICoroutine* __vwsnthis_0;
		::demo::MainWindowConstructor* __vwsnthis_1;

		__vwsnf7_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume_(::vl::reflection::description::ICoroutine* __vwsnctorthis_0, ::demo::MainWindowConstructor* __vwsnctorthis_1);

		void operator()(::vl::vint progress) const;
	};

	struct __vwsnf8_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume__
	{
		::vl::vint progress;
		::vl::reflection::description::ICoroutine* __vwsnthis_0;
		::demo::MainWindowConstructor* __vwsnthis_1;

		__vwsnf8_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize___Resume__(::vl::vint __vwsnctor_progress, ::vl::reflection::description::ICoroutine* __vwsnctorthis_0, ::demo::MainWindowConstructor* __vwsnctorthis_1);

		void operator()() const;
	};

	struct __vwsnf9_Demo_demo_IViewModel_DownloadAsync_
	{
		::vl::Ptr<::vl::reflection::description::IPromise> promise;

		__vwsnf9_Demo_demo_IViewModel_DownloadAsync_(::vl::Ptr<::vl::reflection::description::IPromise> __vwsnctor_promise);

		void operator()(const ::vl::WString& result) const;
	};

	class __vwsnc1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____vl_reflection_description_ICoroutine : public ::vl::Object, public virtual ::vl::reflection::description::ICoroutine
	{
	public:
		::vl::reflection::description::AsyncCoroutine::IImpl* __vwsn_co_impl_;
		::demo::MainWindowConstructor* __vwsnthis_0;

		__vwsnc1_Demo_demo_MainWindowConstructor___vwsn_demo_MainWindow_Initialize____vl_reflection_description_ICoroutine(::vl::reflection::description::AsyncCoroutine::IImpl* __vwsnctor___vwsn_co_impl_, ::demo::MainWindowConstructor* __vwsnctorthis_0);

		::vl::WString __vwsn_co0_text;
		::vl::vint __vwsn_co_state_ = 0;
		::vl::vint __vwsn_co_state_before_pause_ = 0;
		::vl::Ptr<::vl::reflection::description::IValueException> __vwsn_prop_Failure;
		::vl::Ptr<::vl::reflection::description::IValueException> GetFailure() override;
		void SetFailure(::vl::Ptr<::vl::reflection::description::IValueException> __vwsn_value_);
		::vl::reflection::description::CoroutineStatus __vwsn_prop_Status = static_cast<::vl::reflection::description::CoroutineStatus>(0);
		::vl::reflection::description::CoroutineStatus GetStatus() override;
		void SetStatus(::vl::reflection::description::CoroutineStatus __vwsn_value_);
		void Resume(bool __vwsn_raise_exception_, ::vl::Ptr<::vl::reflection::description::CoroutineResult> __vwsn_co_result_) override;
	};

	class __vwsnc2_Demo_demo_IViewModel_DownloadAsync__demo_IStringAsync : public ::vl::Object, public virtual ::demo::IStringAsync
	{
	public:
		__vwsnc2_Demo_demo_IViewModel_DownloadAsync__demo_IStringAsync(::vl::Ptr<::vl::reflection::description::IFuture> __vwsnctor_future);

		::vl::Ptr<::vl::reflection::description::IAsync> __vwsn_mixin_source_;
		bool Execute(const ::vl::Func<void(::vl::Ptr<::vl::reflection::description::CoroutineResult>)>& __vwsn_mixin_parameter_callback, ::vl::Ptr<::vl::reflection::description::AsyncContext> __vwsn_mixin_parameter_context) override;
		::vl::reflection::description::AsyncStatus GetStatus() override;
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