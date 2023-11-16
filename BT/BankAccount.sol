// SPDX-License-Identifier: MIT
pragma solidity ^0.8.8;

contract bank_account {
    mapping(address => uint) public user_balance;
    mapping (address => bool) public is_user;

    function create_account() public {
        require(is_user[msg.sender] == false, "User alread there");
        is_user[msg.sender] = true;
    }

    function deposit(uint amount) public  {
        require(is_user[msg.sender], "User not found");
        user_balance[msg.sender] += amount;
    }

    function withdraw(uint amount) public  {
        require(is_user[msg.sender], "User not found");
        require(user_balance[msg.sender] >= amount, "Insufficient balance");
        user_balance[msg.sender] -= amount;
    }

    function show_balance() view public returns (uint) {
        require(is_user[msg.sender], "User not found");
        return user_balance[msg.sender];
    } 
}
