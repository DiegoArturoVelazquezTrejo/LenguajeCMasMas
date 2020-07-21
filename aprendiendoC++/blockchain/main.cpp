#include <ctime>
#include <vector>
#include <string>
#include <iostream>

using namespace std; 

//Transaction Data 
struct TransactionData{
    // Amount of the transaction 
    double amount; 
    // Sender 
    string senderKey; 
    // Receiver
    string receiverKey;
    // Timestamp of the transaction  
    time_t timestamp;
}; 
// Block Class 
class Block{
    private:
        // Index of the block 
        int index; 
        // Hash of the block 
        size_t blockHash; 
        // Previous hash of the block 
        size_t previousHash; 
        // Method that generates the hash 
        size_t generateHash(); 
    public:
        // Constructor  
        Block(int idx, TransactionData d, size_t prevHash); 
        // Get Original Hash 
        size_t getHash(); 
        // Get previuos hash 
        size_t getPreviuosHash(); 
        // Transaction Data 
        TransactionData data; 
        //Validate Hash 
        bool isHashValid();  
}; 
// Constructor with params 
Block::Block(int idx, TransactionData d, size_t prevHash){
    index = idx; 
    data = d; 
    previousHash = prevHash; 
    blockHash = generateHash(); 
};
// Private Functions 
size_t Block::generateHash(){
    hash<string> hash1; 
    hash<size_t> hash2; 
    hash<size_t> finalHash; 
    string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp); 
    return finalHash(hash1(toHash) + hash2(previousHash)); 
}; 
// Public functions 
size_t Block::getHash(){
    return blockHash; 
}; 
size_t Block::getPreviuosHash(){
    return previousHash; 
}
bool Block::isHashValid(){
    return generateHash() == blockHash; 
}


// Blockchain 
class BlockChain{
    private: 
        Block createGenesisBlock(); 
    public: 
        // Public Chain 
        vector<Block> chain; 
        // Constructor 
        BlockChain(); 
        // Public Functions 
        void addBlock(TransactionData data); 
        bool isChainValid(); 

        Block *getLatestBlock(); 
}; 

// Blockchain constructor 
BlockChain:: BlockChain(){
    Block genesis = createGenesisBlock(); 
    chain.push_back(genesis); 
};
Block BlockChain::createGenesisBlock(){
    time_t current; 
    TransactionData d; 
    d.amount = 0; 
    d.receiverKey = "None"; 
    d.senderKey = "None"; 
    d.timestamp = time(&current); 

    hash<int> hash1; 
    Block genesis(0, d, hash1(0)); 
    return genesis; 
}; 

Block *BlockChain::getLatestBlock(){
    return &chain.back(); 
}
void BlockChain::addBlock(TransactionData d){
    int index = (int)chain.size() - 1; 
    Block newBlock(index, d, getLatestBlock() -> getHash()); 
};

bool BlockChain::isChainValid(){
    vector<Block>::iterator it; 
    int chainLen = (int)chain.size(); 
    for(it = chain.begin(); it != chain.end(); ++it){
        Block currentBlock = *it; 
        if(!currentBlock.isHashValid())
            return false; 
        if(chainLen > 1 ){
            Block previousBlock = *(it -1); 
            if(currentBlock.getPreviuosHash() != previousBlock.getHash()){
                return false; 
            }
        }
    }
    return true; 
};

int main(){
    // Start Blockchain 
    BlockChain AwesomeCoin; 
    // Data for first added Block
    cout << "It compiled!" << endl;  
}