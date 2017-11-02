
#include<bits/stdc++.h>

using namespace std;

struct thing
{
    int a;
    char b;
    bool operator<(const thing& rhs) const
    {
        return a < rhs.a;
    }
};

int main()
{
    std::priority_queue<thing> q;
    thing stuff = {42, 'x'};
    q.push(stuff);
    q.push(thing {100, 'z'});
    q.push(thing {32, 'y'}); // C++11 only
    //q.emplace(424242, 'z'); // C++11 only
    thing otherStuff = q.top();
    q.pop();

    printf("%c",otherStuff.b);

    return 0;

}
