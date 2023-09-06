pragma solidity ^0.8.0;
contract Wallet {
    address _walletLibrary;
    address owner;
    function Wallet(address _owner) {
        _walletLibrary = <address of pre-deployed WalletLibrary>;
        _walletLibrary.delegatecall(bytes4(sha3(“initWallet(address)”)), _owner);
    }
    function withdraw(uint amount) returns (bool success) {
        return _walletLibrary.delegatecall(bytes4(sha3(“withdraw(uint)”)), amount);
    }
    function () payable {
        _walletLibrary.delegatecall(msg.data);
    }
}