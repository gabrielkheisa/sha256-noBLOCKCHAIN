#include <iostream>
#include <string>
#include "sha256.h"

using std::string;
using std::cout;
using std::endl;

struct block {
  string hash_before;
  string transaction;
  string hash_now;
};
 
int main(int argc, char *argv[])
{
    int i=0;
    struct block bloc[6];
    struct block fakebloc[6];
    
    bloc[0].transaction = "A to B 200 coins, B to C 100 coins, C to D 50 coins, D to A 25 coins";
    bloc[1].transaction = "D to E 200 coins, E to F 100 coins, F to G 50 coins, G to D 25 coins";
    bloc[2].transaction = "H to I 200 coins, I to J 100 coins, J to K 50 coins, K to L 25 coins";
    bloc[3].transaction = "X to Z 200 coins, AA to BB 100 coins, CC to DD 50 coins, DD to AA 25 coins";
    bloc[4].transaction = "AAA to BBB 200 coins, BBB to CCC 100 coins, CCC to DDD 50 coins, DDD to AAA 25 coins";
    bloc[5].transaction = "AA to BBB 200 coins, BB to CC 100 coins, CC to DD 50 coins, DD to AA 25 coins";
    
    //view all hash
    /*
    for(i=0; i<=4; i++){
        cout << sha256(bloc[i].transaction) << "\n";
    }
    */
    
    
    //generate hash for current block and save the hash inside its own block
    for(i=0; i<=4; i++){
        bloc[i].hash_now = sha256(bloc[i].transaction);
    }
    
    //save the hash to next block
    for(i=0; i<=4; i++){
        bloc[i+1].hash_before = bloc[i].hash_now;
    }
    
    //check the validity
    for(i=0; i<=4; i++){
        if(bloc[i].hash_now == bloc[i+1].hash_before){
            cout << "Block-" << i << " valid" << "\n";
        }
        else {
            cout << "Block-" << i << " invalid" << "\n";
        }
    }
    
    cout << "\n\n";
    
    //What will happen if fake transaction created
    fakebloc[0].transaction = "A to B 200 coins, B to C 100 coins, C to D 50 coins, D to A 25 coins";
    fakebloc[1].transaction = "D to E 200 coins, E to F 100 coins, F to G 50 coins, G to D 25 coins";
    fakebloc[2].transaction = "H to I 200 coins, I to J 133 coins, J to K 50 coins, K to L 25 coins"; //modified chain
    fakebloc[3].transaction = "X to Z 200 coins, AA to BB 100 coins, CC to DD 50 coins, DD to AA 25 coins";
    fakebloc[4].transaction = "AAA to BBB 200 coins, BBB to CCC 100 coins, CCC to DDD 50 coins, DDD to AAA 25 coins";
    fakebloc[5].transaction = "AA to BBB 200 coins, BB to CC 100 coins, CC to DD 50 coins, DD to AA 25 coins";
    
    //generate hash for fake block and save the hash inside its own block
    for(i=0; i<=4; i++){
        fakebloc[i].hash_now = sha256(fakebloc[i].transaction);
    }
    
    //save the hash to next fake block
    for(i=0; i<=4; i++){
        fakebloc[i+1].hash_before = fakebloc[i].hash_now;
    }
    
    //compare original block to fake block
    for(i=0; i<=4; i++){
        if(bloc[i].hash_now == fakebloc[i].hash_now){
            cout << "Block-" << i << " valid" << "\n";
        }
        else {
            cout << "Block-" << i << " invalid" << "\n";
            cout << "Rejected" << "\n";
            break;
        }
    }
    
    return 0;
}