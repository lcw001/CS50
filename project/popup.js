// popup.js

// Set global variables
let form = document.getElementById("inputform");
let userInput = document.getElementById("userInput");
let submitButton = document.getElementById("submitButton");

document.addEventListener("DOMContentLoaded", function ()
{
  // Regex used to validate ipaddress format and specal class
  const ipv4_cidr = /^(?:(?:[01]?\d?\d|2[0-4]\d|25[0-5])\.){3}(?:[01]?\d?\d|2[0-4]\d|25[0-5])(?:\/(?:[0-9]|[12][0-9]|3[0-2]))?$/;
  //const correct_ipv4 = /^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/;
  //const correct_cidr = /^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\/(?:3[0-2]|[1-2]?[0-9])$/;
  const private_ip = /^(?:(10\.(?:\d{1,3}\.){2}\d{1,3}|172\.(?:1[6-9]|2[0-9]|3[0-1])\.(?:\d{1,3}\.){1,2}\d{1,3}|192\.168\.(?:\d{1,3}\.){1,2}\d{1,3})(?:\/(?:[0-9]|[12][0-9]|3[0-2]))?)$/;
  const multicast_ip = /^(22[4-9]|23[0-9])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$/;
  const multicastcidr_ip = /^(22[4-9]|23[0-9])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])(?:\/(?:[0-9]|[12][0-9]|3[0-2]))?$/;
  const loopback_ip = /^127\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])(?:\/(?:[0-9]|[12][0-9]|3[0-2]))?$/;
  const reserved_ip = /^(?:(?:2[4-9][0-9]|25[0-5])\.(?:\d{1,3}\.){2}(?:\d{1,3})|255\.(?:\d{1,3}\.){3})(?:\/(?:[0-9]|[12][0-9]|3[0-2]))?$/;
  const linklocal_ip = /^(?:169\.254\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-4])\.(?:[01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-4]))(?:\/(?:[0-9]|[12][0-9]|3[0-2]))?$/;
  const defaultroute_ip = /^(0\.0\.0\.0|0\.0\.0\.0\/0)$/;

  // for demo: makes api call on page load and displays returned data
  window.addEventListener("load",function ()
  {
    //userInputValue = "192.168.1.0/27";
    //ip_validation(userInputValue);
    //reset_function();
    userInput.focus()
  });

  //===================================================================  
  // Submit button click or enter key press event
  submit_button.addEventListener("click", function(event)
  {
    event.preventDefault();
    console.log("userInput:  " + userInput.value); // Test if userInput captured
    console.log("click eventlistener  -->OK");
  
    ip_validation(userInput.value);// Call ip_validation function
    reset_function; 
  });
  //===================================================================
  function ip_validation(userInputValue)
  {
      let ipAddress = userInputValue;
      if (ipAddress === "") {
          document.getElementById("userInput").placeholder =
          "8.8.8.8 or 8.8.8.8/25 Required";
          document.getElementById("userInput").focus();
          console.log("No user entry");      
          return;      
      }   
      // validate ipaddress or cidr notation
        
      if (ipAddress.match(ipv4_cidr))
      {
          console.log("ip_validation -->OK");
          // if multicast  not cidr call ip_param
          if (multicast_ip.test(ipAddress))
          {
            ip_param(ipAddress); // Call ip_param function
            console.log("ip valid, multicast = Y, cidr = N");
            return;           
          }
          else
          {
            if (multicastcidr_ip.test(ipAddress)) // multicast cidr confirmation
            {
              console.log("ip valid, multicast = Y, cidr = Y");
              const confirmCIDR = confirm("CIDR notation is not usually used with multicast addresses. Continue?");
              {
                if (!confirmCIDR) // if cancel
                {
                  console.log("cancel multicast cidr");
                  reset_function();      
                  return;
                }
                else
                {
                  console.log("continue multicast cidr");
                  ip_param(ipAddress); // continue with multicast cidr
                  return;
                }
              }        
            }
            else
            {
              param = ""
              ip_param(ipAddress); // ipv4 valid, no multicast_ip: continue
              return;
            }
          }
        }
        else      
        {
          // If user input is invalid, prompts for re-entry
          console.log("invalid ipaddress / cidr notation");          
          alert("Invalid IP address or CIDR notation");

          //reset_function();
          reset_function();
          return;
        }
    }
   
    //==================================================================
    function ip_param(ipAddress)
    {      
      let param = "" // Declaration variable
      console.log("ipAddress = " + ipAddress);
      
      if (ipAddress.match(multicast_ip))
      {
        param = "Multicast";
      }
      else if (ipAddress.match(private_ip))
      {
        param = "Private";
      }
      else if (ipAddress.match(loopback_ip))
      {
        param = "Loopback";
      }
      else if (ipAddress.match(linklocal_ip))
      {
        param = "Link Local";
      }
      else if (ipAddress.match(defaultroute_ip))
      {
        param = "Default Route"
      }
      else if (ipAddress.match(reserved_ip))
      {
        param = "Reserved";
      }
      else
      {
        param = "";
      }

      console.log("ip_param = " + param);
      console.log("ip_param function -->OK");

      api_call(ipAddress,param); // Call api_call function
      return;
    }
    //===================================================================
    function api_call(ipAddress,param)
    {
      // Make api call using valid user input
      // Converts JSON response to JS object
      const apiUrl = `https://networkcalc.com/api/ip/${ipAddress}?binary=true`;
      data=""
      fetch(apiUrl)
        .then((response) => response.json())
        .then((data) => {
          parse_data = data;
          console.log("api_call -->OK");
          console.log(parse_data);
          map_data(data,param); // Call map_data function
        })
        // Bad API response - prompts for re-entry
        .catch((error) => {
          alert("Error fetching data. Please try again.");
        });  
      return;
    }
    //===================================================================        
    function map_data(parse_data,param)
    {
      // Map data obj and update html table
      document.getElementById("cidr_notation").textContent = parse_data.address.cidr_notation; ("<br>");
      document.getElementById("subnet_bits").textContent = parse_data.address.subnet_bits; ("<br>");
      document.getElementById("subnet_mask").textContent = parse_data.address.subnet_mask; ("<br>");
      document.getElementById("wildcard_mask").textContent = parse_data.address.wildcard_mask; ("<br>");
      document.getElementById("network_address").textContent = parse_data.address.network_address; ("<br>");
      document.getElementById("broadcast_address").textContent = parse_data.address.broadcast_address; ("<br>");
      document.getElementById("assignable_hosts").textContent = parse_data.address.assignable_hosts; ("<br>");
      document.getElementById("first_assignable_host").textContent = parse_data.address.first_assignable_host; ("<br>");
      document.getElementById("last_assignable_host").textContent = parse_data.address.last_assignable_host; ("<br>");
      document.getElementById("binary_octet1").textContent = parse_data.address.binary.octet_1; ("<br>");
      document.getElementById("binary_octet2").textContent = parse_data.address.binary.octet_2; ("<br>");
      document.getElementById("binary_octet3").textContent = parse_data.address.binary.octet_3; ("<br>");
      document.getElementById("binary_octet4").textContent = parse_data.address.binary.octet_4; ("<br>");
      document.getElementById("binary_address").textContent = parse_data.address.binary.address; ("<br>");
      document.getElementById("binary_subnet_mask").textContent = parse_data.address.binary.subnet_mask; ("<br>");
      document.getElementById("binary_wildcard_mask").textContent = parse_data.address.binary.wildcard_mask; ("<br>");
      document.getElementById("binary_network_address").textContent = parse_data.address.binary.network_address; ("<br>");
      document.getElementById("binary_broadcast_address").textContent = parse_data.address.binary.broadcast_address; ("<br>");
      document.getElementById("binary_first_assignable_address").textContent = parse_data.address.binary.first_assignable_host; ("<br>");
      document.getElementById("binary_last_assignable_address").textContent = parse_data.address.binary.last_assignable_host; ("<br>");

      document.getElementById("param").textContent =  param;

      console.log("map_data fxn: ip_param = " + param);
      console.log("map_data -->OK");
      return;
    }
  //====================================================================
  // Copy JSON data in table to clipboard
  copy_button.addEventListener("click", copy_function);
  async function copy_function() {
    let display_box_contents = document.getElementById("display_box");
    copy_button.classList.toggle("active");
    try {
      await navigator.clipboard.writeText(display_box_contents.innerText);
      display_box_contents.style.background = "rgb(235, 233, 233)";
      setTimeout(function () {
        display_box_contents.style.background = "rgb(255, 255, 255)";
      }, 300);
      console.log("copy function -->OK");
    } catch (err) {
      console.log("failed to copy");
      alert("Failed to copy");
    }
  }
  //===================================================================
  // Reset form and clear data
  reset_button.addEventListener("click", reset_function);

  async function reset_function()
  {
    var spanIdsToClear = [
        "cidr_notation", "param", "subnet_bits", "subnet_mask",
        "wildcard_mask", "network_address", "broadcast_address", "assignable_hosts",
        "first_assignable_host", "last_assignable_host", "binary_octet1", 
        "binary_octet2", "binary_octet3", "binary_octet4", "binary_address",
        "binary_subnet_mask", "binary_wildcard_mask", "binary_network_address",
        "binary_broadcast_address", "binary_first_assignable_address",
        "binary_last_assignable_address"
      ];
    
      spanIdsToClear.forEach(function(id) {
        var spanElement = document.getElementById(id);
        if (spanElement) {
          spanElement.textContent = "";
        }
      });
    param = "";
    // Reset form and set focus to input
    inputform.reset();
    userInput.focus();
    console.log("reset_function -->OK");

    return;
  }
  
  // Opens README file in a new window
  const openReadmeButton = document.getElementById("readme");
  openReadmeButton.addEventListener("click", function ()
  {
    chrome.tabs.query({active:true, currentWindow:true}, function (tabs)
    {
      const currentTab = tabs[0];
      chrome.windows.create({
        url: chrome.runtime.getURL("README.md"),
        type: "popup",
        width: currentTab.width,
        height: currentTab.height
      });
    });
  });
});
