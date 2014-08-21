<?php
function landing_pages_views_query_alter(&$view, &$query) {
  switch($view->name) {
    case 'generic_landing':  
       // test  
      //$query->where[0]['clauses'][4] = '(node.type in ('%d'))';	   
      //$query->where[0]['args'][4] = 'part';
      if ($node = menu_get_object()) {
	 /*   $filter_type = $node->field_filter_type['0']['value'];
	    $view->query->add_where('landing_pages_groups', "node.type = '%s'", 'part');
     */
	 /*   $filter_manufacturer = $node->field_filter_manufacturer['0']['value'];
	    $view->query->add_where('landing_pages_groups', "term_data.tid = '305'", 'Isuzu Parts & Trucks');
		
	    $filter_part_categories = $node->field_filter_part_categories['0']['value'];
	    $view->query->add_where('landing_pages_groups', "term_data2.tid = '96'", $filter_part_categories); 
	*/
	  $filter_type = $node->field_filter_type['0']['value'];
	  $view->query->where[0]['args'][0] = $filter_type;	
	
	  $filter_manufacturer = $node->field_filter_manufacturer['0']['value'];
	  $view->query->where[0]['args'][1] = $filter_manufacturer;
	  
		  if ($filter_type == 'truck') {
		  $view->query->where[0]['clauses'][3] = 'term_node2.tid != %d';
		  $view->query->where[0]['args'][2] = '1';		    
		  }
	  
		  else { 
		  $filter_part_categories = $node->field_filter_part_categories['0']['value'];
		  $view->query->where[0]['args'][2] = $filter_part_categories;
		  }
	  }
	  
	  //dpm($query);
      break;
  }
}

