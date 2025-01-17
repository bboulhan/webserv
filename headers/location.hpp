/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:21 by aer-razk          #+#    #+#             */
/*   Updated: 2022/12/11 20:45:46 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROUTES_HPP
#define		ROUTES_HPP
#include	"includes.hpp"

class location
{
	private:
		std::string					root;
		std::vector<std::string>	allow_methods;
		std::string					location_path;
		std::string					index;
		bool						autoindex;
		std::string					cgi_path;
		std::string					cgi_extension;
	public:
		std::vector<std::string>	cont_location;
		//orthodox canonical class methods
		location();
		~location();
		//getters
		std::string					get_root(void);
		std::string					get_location_path(void);
		std::string					get_index(void);
		std::string					get_method();
		bool						get_autoindex();
		std::string					get_cgi_path();
        std::string					get_cgi_extension();
		//setters
		void						set_location_path();
		void						set_allow_methods();
		void						set_root();
		void						set_index(bool autoindex);
		//void						set_autoindex();
		void						set_cgi_extension();
		void						set_cgi_path();

		//methods
		std::vector<std::string>	checknsearch(std::string var);
};
#endif