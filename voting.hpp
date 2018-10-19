
namespace eosio {

	//@abi table votes
	struct votes{
		uint64_t goal_id;
		account_name host;
		uint64_t rotation_num;	
		uint64_t power;

		uint64_t primary_key()const { return goal_id; }
		account_name by_host() const {return host;}

	    EOSLIB_SERIALIZE( votes, (goal_id)(host)(rotation_num)(power))
    };

    typedef eosio::multi_index< N(votes), votes,
    indexed_by<N(host), const_mem_fun<votes, account_name, &votes::by_host>>> votes_index;

//Indexed by host;

	//@abi action
	struct vote	{
		account_name voter;
		uint64_t goal_id;
	};
}