// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreBlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/GenericCommands.h"
#include "Input/Events.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Framework/Application/SlateApplication.h"


void UCoreBlueprintFunctionLibrary::TestClick(FVector2D Position, APlayerController* PlayerController) 
{

    FKey MouseButton = EKeys::LeftMouseButton;
    FSlateApplication& SlateApp = FSlateApplication::Get();
    /*
    SlateApp.ExternalUIChange(true);


    SlateApp.ActivateGameViewport();
    //FSlateApplication::ForceRedrawWindow;
   // FSlateApplication::GetGameViewport;


    //SetSlateUILogger(MakeShareable(new FConsoleEventLogger()));

    FInputModeGameAndUI InputMode;
    PlayerController->SetInputMode(InputMode);
    FViewport* Viewport = GEngine->GameViewport->Viewport;
    if (Viewport)
    {
        FViewportClient* ViewportClient = Viewport->GetClient();
        if (ViewportClient)
        {
            ViewportClient->CaptureMouseOnClick();
        }
    }
  */
    //FSlateApplication::RegisterViewport(Viewport);

    // TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();
    //SlateApp.ActivateGameViewport();
    //SlateApp.ClearAllUserFocus();

    //GetTopLevelWindows()
    //FWidgetPath WidgetsUnderCursor = SlateApp.LocateWindowUnderMouse(SlateApp.GetCursorPos(), SlateApp.GetTopLevelWindows());

    PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Pressed, 0, false);

    FPointerEvent MouseEvent(0, Position, Position, TSet<FKey>(), MouseButton, 0, FModifierKeysState());

    SlateApp.ProcessMouseButtonDownEvent(SlateApp.GetActiveTopLevelWindow()->GetNativeWindow(), MouseEvent);
   // SlateApp.ProcessMouseButtonUpEvent(MouseEvent);

     // Simulate a mouse button press
   // SlateApp.ProcessMouseButtonDownEvent(SlateApp.GetVisibleMenuWindow()->GetNativeWindow(), MouseEvent);
    // Simulate a mouse button release
    //SlateApp.ProcessMouseButtonUpEvent(MouseEvent);


    // Simulate a mouse button press
    //SlateApp.ProcessMouseButtonDownEvent(SlateApp.GetActiveModalWindow()->GetNativeWindow(), MouseEvent);
   // SlateApp.ProcessMouseButtonUpEvent(MouseEvent);

    SlateApp.ProcessMouseButtonDownEvent(SlateApp.GetActiveTopLevelRegularWindow()->GetNativeWindow(), MouseEvent);
    //SlateApp.ProcessMouseButtonUpEvent(MouseEvent);

    auto Interacts = SlateApp.GetInteractiveTopLevelWindows();

    for (auto Interact : Interacts)
    {
        SlateApp.ProcessMouseButtonDownEvent(Interact->GetNativeWindow(), MouseEvent);
        //SlateApp.ProcessMouseButtonUpEvent(MouseEvent);
    }

    SlateApp.ProcessMouseButtonDownEvent(SlateApp.GetPlatformApplication()->GetWindowUnderCursor(), MouseEvent);
    //SlateApp.ProcessMouseButtonUpEvent(MouseEvent);


    //SlateApp.ProcessMouseButtonDownEvent(SlateApp.GetInteractiveTopLevelWindows(), MouseEvent);
   // SlateApp.ProcessMouseButtonUpEvent(MouseEvent);

    /*
    for (auto Window : SlateApp.GetTopLevelWindows())
    {
        // Simulate a mouse button press
        SlateApp.ProcessMouseButtonDownEvent(Window->GetNativeWindow(), MouseEvent);
        // Simulate a mouse button release
        SlateApp.ProcessMouseButtonUpEvent(MouseEvent);
    }*/

    //FSlateApplication::Get().SetAllUserFocus(WidgetsUnderCursor, EFocusCause::WindowActivate);

    //TSharedPtr<FGenericWindow> Platform = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();
    
   // if (!Platform)
   // {
  //      return;
  //  }
    //TSharedPtr<FGenericWindow> PlatformWindow1 = SlateApp.FindWidgetWindow(WidgetsUnderCursor);

   
   // FSlateApplication::Get().ActivateGameViewport();
    //TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();
   
    //TArray<TSharedRef<SWindow>> OutWindows;
    //SlateApp.GetAllVisibleWindowsOrdered(OutWindows);

    //SlateApp.GetInteractiveTopLevelWindows();

    //TArray<TSharedPtr<SWindow>> TopLevelWindows;

    // Simulate a mouse button press
   // SlateApp.ProcessMouseButtonDownEvent(Platform, MouseEvent);

    // Simulate a mouse button release
    //SlateApp.ProcessMouseButtonUpEvent(MouseEvent);


    FKey MouseButton1 = EKeys::LeftMouseButton;
    // Get the slate application.

    FVector2D MousePosition;
    PlayerController->GetMousePosition(Position.X, Position.Y);

    //FPointerEvent MouseEvent(0, MousePosition, MousePosition, TSet<FKey>(), MouseButton1, 0, FModifierKeysState());

    TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();

    FViewportClient* Client = GEngine->GameViewport->Viewport->GetClient();
    FKey MouseLMB = EKeys::LeftMouseButton;
    Client->InputKey(GEngine->GameViewport->Viewport, 0, MouseLMB, EInputEvent::IE_Pressed);
    Client->InputKey(GEngine->GameViewport->Viewport, 0, MouseLMB, EInputEvent::IE_Released);

    FSlateApplication::Get().ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);
    //FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);
   
    //PlayerController->SetMouseLocation(Position.X + 10, Position.Y + 10);

   FSlateApplication::Get().ProcessMouseButtonDoubleClickEvent(PlatformWindow, MouseEvent);
   //FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

    PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Pressed, 0, false);
    PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Released, 0, false);

   //UGameplayStatics::GetPlayerController(GWorld, 0)->Tap(Position, ETouchIndex::Touch1, 1.0f);
}

void UCoreBlueprintFunctionLibrary::TestClickOff(FVector2D Position, APlayerController* PlayerController)
{
    /*
    FInputModeGameAndUI InputMode;
    PlayerController->SetInputMode(InputMode);
    FViewport* Viewport = GEngine->GameViewport->Viewport;
    if (Viewport)
    {
        FViewportClient* ViewportClient = Viewport->GetClient();
        if (ViewportClient)
        {
            ViewportClient->CaptureMouseOnClick();
        }
    }
      */
    PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Released, 0, false);
    FKey MouseButton = EKeys::LeftMouseButton;
    // Get the slate application.
    FSlateApplication& SlateApp = FSlateApplication::Get();
    
    FVector2D MousePosition;
    PlayerController->GetMousePosition(Position.X, Position.Y);
  
    FPointerEvent MouseEvent(0, MousePosition, MousePosition, TSet<FKey>(), MouseButton, 0, FModifierKeysState());
    //TSharedPtr<FGenericWindow> Platform = SlateApp.LocateWindowUnderMouse(SlateApp.GetCursorPos(), SlateApp.GetInteractiveTopLevelWindows()).GetWindow()->GetNativeWindow();
   // if (!Platform)
   // {
  //      return;
   // }

    //TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();

    // FViewportClient* Client = GEngine->GameViewport->Viewport->GetClient();
    // FKey MouseLMB = EKeys::LeftMouseButton;
    // Client->InputKey(GEngine->GameViewport->Viewport, 0, MouseLMB, EInputEvent::IE_Pressed);
    // Client->InputKey(GEngine->GameViewport->Viewport, 0, MouseLMB, EInputEvent::IE_Released);

    //FSlateApplication::Get().ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);
    FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

    // PlayerController->SetMouseLocation(Position.X + 10, Position.Y + 10);

    // FSlateApplication::Get().ProcessMouseButtonDoubleClickEvent(PlatformWindow, MouseEvent);
    // FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

    // PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Pressed, 0, false);
    // PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Released, 0, false);

    // UGameplayStatics::GetPlayerController(GWorld, 0)->Tap(Position, ETouchIndex::Touch1, 1.0f);





}

void UCoreBlueprintFunctionLibrary::GetWidgetUnderCursor() 
{
      // Get a reference to the singleton instance of the slate application.
      FSlateApplication& MySlateApplication = FSlateApplication::Get();

      // Find a "widget tree path" of all widgets under the mouse cursor.
      // This path will contain not only the top-level widget, but all widgets underneath.
      // For example, if the mouse cursor was over a Button with a Text widget inside of it, then the last
      // widget in the widget path would be the Text widget, and the next to last widget would be the Button widget.
      FWidgetPath WidgetsUnderCursor = MySlateApplication.LocateWindowUnderMouse(
          MySlateApplication.GetCursorPos(), MySlateApplication.GetInteractiveTopLevelWindows());

      FString Result = TEXT("");
      if (WidgetsUnderCursor.IsValid())
      {
          Result += TEXT(" Count:") + FString::FromInt(WidgetsUnderCursor.Widgets.Num());

          for (int32 Idx = 0; Idx < WidgetsUnderCursor.Widgets.Num(); ++Idx)
          {
              FArrangedWidget& Widget = WidgetsUnderCursor.Widgets[Idx];
            return;
              //Result += TEXT(" ") + Widget.Widget->ToString();
          }
      }

      // Print out a quick summary of all widgets that were found under the mouse.
}

void UCoreBlueprintFunctionLibrary::ProcessEditorClick(FVector2D atCoordinates)
{
      FSlateApplication& slateApplication = FSlateApplication::Get();
      const TSet<FKey> pressedButtons = TSet<FKey>({EKeys::LeftMouseButton});
      FPointerEvent mouseMoveAndClickEvent(0, slateApplication.CursorPointerIndex, atCoordinates, FVector2D(0, 0), pressedButtons,
          EKeys::LeftMouseButton, 0, slateApplication.GetPlatformApplication()->GetModifierKeys());
      TSharedPtr<FGenericWindow> genericWindow;
      bool mouseClick = slateApplication.ProcessMouseButtonDoubleClickEvent(genericWindow, mouseMoveAndClickEvent);
}
