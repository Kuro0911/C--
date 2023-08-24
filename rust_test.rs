// block.rs
pub struct Block {
    timestamp: i64,                
    pre_block_hash: String,         
    hash: String,                   
    transactions: Vec<Transaction>, 
    nonce: i64,                     
    height: usize,                  
}

pub fn new_block(pre_block_hash: String, transactions: &[Transaction], height: usize) -> Block {
        let mut block = Block {
            timestamp: crate::current_timestamp(),
            pre_block_hash,
            hash: String::new(),
            transactions: transactions.to_vec(),
            nonce: 0,
            height,
        };
        let pow = ProofOfWork::new_proof_of_work(block.clone());
        let (nonce, hash) = pow.run();
        block.nonce = nonce;
        block.hash = hash;
        return block;
    }

// pow.rs

        
pub struct ProofOfWork {
    block: Block,
    target: BigInt,
}

pub fn run(&self) -> (i64, String) {
        let mut nonce = 0;
        let mut hash = Vec::new();
        println!("Mining the block");
        while nonce < MAX_NONCE {
            let data = self.prepare_data(nonce);
            hash = crate::sha256_digest(data.as_slice());
            let hash_int = BigInt::from_bytes_be(Sign::Plus, hash.as_slice());

          
            if hash_int.lt(self.target.borrow()) {
                println!("{}", HEXLOWER.encode(hash.as_slice()));
                break;
            } else {
                nonce += 1;
            }
        }
        println!();
        return (nonce, HEXLOWER.encode(hash.as_slice()));
    }
}


// transaction.rs

pub struct Transaction {
    id: Vec<u8>,         
    vin: Vec<TXInput>,   
    vout: Vec<TXOutput>, 
}
