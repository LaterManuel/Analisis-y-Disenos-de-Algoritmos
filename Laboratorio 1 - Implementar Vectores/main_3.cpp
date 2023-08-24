#include <iostream>

using namespace std;
struct Vector
{
    int* m_pVect, // Pointer to the buffer
        m_nCount, // Control how many elements are actually used
        m_nMax, // Control how many are allocated as maximum
        m_nDelta; // To control the growing
};
void Resize(Vector* pThis)
{
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    // The Max has to be increased by delta
    pThis->m_nMax += pThis->m_nDelta;
}
void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verify the overflow
        Resize(pThis); // Resize the vector before inserting elem
    // Insert the element at the end of the sequence
    pThis->m_pVect[pThis->m_nCount++] = elem;
}


int main()
{
    Vector lista;
    lista.m_pVect = NULL;
    lista.m_nCount = 0;
    lista.m_nMax = 0;
    lista.m_nDelta = 10;

    Vector* a = &lista;
    for (int uu = 0; uu <= 10; uu++) {
        Insert(a, uu);
    }
    for (int uu = 0; uu <= 10; uu++) {
        cout << lista.m_pVect[uu];
    }
}