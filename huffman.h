#pragma once

struct Node {
    uint32_t frequency = 0;
    void* nextNode = nullptr;
};

typedef struct Node Node;