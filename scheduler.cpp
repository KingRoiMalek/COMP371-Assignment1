#include <cstdio>

#include <GLFW/glfw3.h>

#include "scheduler.hpp"

Scheduler::Scheduler(double updateInterval) {
    this->updateInterval = updateInterval;
}
Scheduler::~Scheduler() {
    return;
}
bool Scheduler::shouldUpdate() {
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    secondAccumulator += deltaTime;
    updateAccumulator += deltaTime;
    if (secondAccumulator >= 1) {
        secondAccumulator -= 1;
        printf("FPS: %d\n", FPS);
        FPS = 0;
    }
    if (updateAccumulator >= updateInterval) {
        updateAccumulator -= updateInterval;
        return true;
    }
    return false;
}
