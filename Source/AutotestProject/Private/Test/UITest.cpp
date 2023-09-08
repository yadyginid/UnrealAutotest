// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_AUTOMATION_TESTS
#include "Test/UITest.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/GenericCommands.h"
#include "Input/Events.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Framework/Application/SlateApplication.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FClickTest, "AutotestProject.UITest.Click",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMoveMouseTest, "AutotestProject.UITest.MoveMousePosition",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);


bool FClickTest::RunTest(const FString& Parameters) 
{
    FVector2D Position = FVector2D(100, 100);
    MoveMouse(Position);
    //ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(5.0f));
    LeftMouseClick(Position);
    return true;
}

bool FMoveMouseTest::RunTest(const FString& Parameters)
{
    FVector2D Position = FVector2D(100, 100);
    MoveMouse(Position);
    return true;
}

bool MoveMouse(FVector2D& Position)
{
    FSlateApplication& SlateApp = FSlateApplication::Get();
    SlateApp.SetCursorPos(Position);

    return true;
}

bool LeftMouseClick(FVector2D& MousePosition)
{
    FKey MouseButton = EKeys::LeftMouseButton;
    //Get the slate application.
    FSlateApplication& SlateApp = FSlateApplication::Get();
 

    FPointerEvent MouseEvent(0, MousePosition, MousePosition, TSet<FKey>(), MouseButton, 0, FModifierKeysState());
    TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();
    FSlateApplication::Get().ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);

    /*
    FPointerEvent MouseEvent(0, MousePosition, MousePosition, TSet<FKey>(), MouseButton, 0, FModifierKeysState());

    // Simulate the mouse button down and up events.
    TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();

    FSlateApplication::Get().SetCursorPos(MousePosition);
    // bool isClick = FSlateApplication::Get().ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);
    // FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

    // Simulate mouse down at position.
    // SlateApp.ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);
    // FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

    // FSlateApplication::Get().OnMouseDown(PlatformWindow, EMouseButtons::Left);
    // FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

    FSlateApplication::Get().ProcessMouseButtonDoubleClickEvent(PlatformWindow, MouseEvent);
    FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);
    */
    return true;
}


#endif