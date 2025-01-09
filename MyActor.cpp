// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    now_Pos = FVector2D(0, 0);
    totDist = 0;;
    evCnt = 0;;
}

void TestUELogExamples()
{
    // 1. �Ϲ� �α�(Log) - �����ڰ� ������� ���� ����ϴ� �⺻ �޽���
    UE_LOG(LogTemp, Log, TEXT("Game has started. Player has joined the game."));

    // 2. �߿� ����(Display) - �׻� ǥ�õǴ� ���� �޽���
    FString PlayerName = TEXT("Player1");
    UE_LOG(LogTemp, Display, TEXT("Welcome, %s! Enjoy the game."), *PlayerName);

    // 3. ���(Warning) - ������ ������ ���� �� ��� ���
    int PlayerHealth = 50;
    if (PlayerHealth < 100)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player health is below maximum: %d"), PlayerHealth);
    }

    // 4. ����(Error) - ���࿡ ������ �� �� �ִ� ����
    int AmmoCount = 0;
    if (AmmoCount == 0)
    {
        UE_LOG(LogTemp, Error, TEXT("No ammo left! Player cannot shoot."));
    }

    // 5. ġ���� ����(Fatal) - ���α׷��� �� �̻� ����� �� ���� ��� (�����)
    bool bCriticalFailure = true;
    if (bCriticalFailure)
    {
        UE_LOG(LogTemp, Fatal, TEXT("A critical failure occurred. Shutting down..."));
    }

    // 6. ���ڿ� ���� - �پ��� �����͸� �� �޽����� ���
    int Score = 150;
    int TimeLeft = 120;
    UE_LOG(LogTemp, Log, TEXT("Score: %d, Time Left: %d seconds."), Score, TimeLeft);

    // 7. �ε��Ҽ���(Floating Point) �� ���
    float PlayerSpeed = 325.5f;
    UE_LOG(LogTemp, Display, TEXT("Player speed: %.2f units/sec"), PlayerSpeed);

    // 8. ���� �ɰ��� ��� - ���� ���¿� ���� �α׸� ����
    bool bIsPaused = true;
    if (bIsPaused)
    {
        UE_LOG(LogTemp, Warning, TEXT("Game is currently paused."));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Game is running normally."));
    }

    // 9. ������ �޽��� (Developer Note)
    UE_LOG(LogTemp, Display, TEXT("This message is for developers to debug the game state."));

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    move();
}



// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move()
{
    for (int32 i = 0; i < 10; i++)
    {
        int dx = step();
        int dy = step();
        FVector2D Vec = FVector2D(now_Pos.X + dx, now_Pos.Y + dy);
        VectorArray.Add(Vec); // X, Y ���� ���Ƿ� ����
        totDist += distance(now_Pos, Vec);
        now_Pos = Vec;
        // ������ ���
        if (createEvent())
        {
            UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
            evCnt++;
        }
        UE_LOG(LogTemp, Warning, TEXT("Vector %d: X = %f, Y = %f"), i, Vec.X, Vec.Y);
    }
    UE_LOG(LogTemp, Warning, TEXT("total Distance: %f"), totDist);
    UE_LOG(LogTemp, Warning, TEXT("total event count: %d"), evCnt);
}

int32_t AMyActor::step()
{
    return FMath::RandRange(0, 1); // 0 ~ 1�� ���� ����
}

int32 AMyActor::createEvent()
{
    return FMath::RandRange(0, 1);
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
    float dx = first.X - second.X;
    float dy = first.Y - second.Y;
    return FMath::Sqrt(dx * dx + dy * dy);
}