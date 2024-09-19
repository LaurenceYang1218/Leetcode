/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* head = new PolyNode();
        PolyNode* curr = head;
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                PolyNode* p = new PolyNode(poly1->coefficient, poly1->power);
                curr->next = p;   
                poly1 = poly1->next;
                curr = curr->next;
            }else if (poly1->power < poly2->power) {
                PolyNode* p = new PolyNode(poly2->coefficient, poly2->power);
                curr->next = p;
                poly2 = poly2->next;
                curr = curr->next;
            }else {
                if (poly1->coefficient + poly2->coefficient != 0) {
                    PolyNode* p = new PolyNode(poly1->coefficient + poly2->coefficient, poly1->power);
                    curr->next = p;
                    curr = curr->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
            
        }

        if (poly1 == nullptr) {
            curr->next = poly2;
        }
        
        if (poly2 == nullptr) {
            curr->next = poly1;
        }

        return head->next;
    }
};