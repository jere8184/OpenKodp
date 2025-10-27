
#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <print>

#include "tinyxml2.h"

#include "page_parser.hpp"

namespace PageParser
{

using Node = const tinyxml2::XMLNode;

Node* find_xml_node(Node* node, const std::string& value)
{
	if (node->Value() == value)
	{
		return node;
	}

	Node* result = nullptr;

	Node* first_child = node->FirstChild();

	if (first_child != nullptr)
		result = find_xml_node(first_child, value);

	if (result == nullptr)
	{
		const Node* sibling = node->NextSibling();

		if (sibling != nullptr)
			result = find_xml_node(sibling, value);
	}
	return result;
	
};

std::vector<Node*> find_page_nodes(const tinyxml2::XMLDocument& document)
{
	Node* element = document.FirstChildElement();
	Node* pages_tag = find_xml_node(element, "pages");


	std::vector<Node*> result;
	if (pages_tag != nullptr)
	{
		Node* page_node = pages_tag->Parent()->NextSiblingElement()->FirstChild();

		while (page_node != nullptr && page_node->Value() != "dict")
		{
			result.push_back(page_node);
			page_node = page_node->NextSibling();
		}
		
	}

	return result;
}

std::pair<std::string, Values> extract_key_value(Node* key_node)
{
	const std::string& key_name = key_node->FirstChild()->Value();
	Node* value_node = key_node->NextSiblingElement();
	Values values;

	if (value_node->Value() == std::string("string"))
		values.push_back(value_node->FirstChild()->Value());
	else if (value_node->Value() == std::string("array"))
	{
		Node* array_value = value_node->FirstChild();
		while (array_value != nullptr)
		{
			values.push_back(array_value->FirstChild()->Value());
			array_value = array_value->NextSibling();
		}
	}

	return {key_name, values}; 
};

std::vector<Page> parse_page_nodes(const std::vector<Node*>& pages_nodes)
{
	std::vector<Page> pages;
	for (Node* page_node : pages_nodes)
	{
		Page page;

		Node* child = page_node->FirstChild();

		while (child != nullptr)
		{
			if (child->Value() == std::string("key"))
				page.insert(extract_key_value(child));

			child = child->NextSiblingElement("key");
		}

		pages.push_back(page);
	}

	return pages;
} 

std::vector<Page> get_pages(std::string kodp_xml)
{	
	tinyxml2::XMLDocument document;
	document.LoadFile(kodp_xml.c_str());
	return parse_page_nodes(find_page_nodes(document));
}

}