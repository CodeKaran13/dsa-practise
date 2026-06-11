//  Copyright (c) 2026 CodeKaranGames. All rights reserved.
//  This file contains original source code owned by CodeKaranGames.
//  Unauthorized copying, modification, distribution, or use is
//  prohibited unless explicitly permitted.
//

#ifndef DSA_PRATISE_LISTNODE_H
#define DSA_PRATISE_LISTNODE_H


struct ListNode
{
    int val;
    ListNode* next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


#endif //DSA_PRATISE_LISTNODE_H
