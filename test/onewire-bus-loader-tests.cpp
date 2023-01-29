// The Bus Loader relies on the json configuration stored in a spiff file named "onewire.jso"
// the Bus Loader Load function should.

// determine if a onewire.jsofile exists
// if not create a default configuration with one bus using pin 15 with no sensors configured
// use of the default configuration should be notified
// the default pin in use should be notified
// the name of the configuration file and a link to the template should be notified

// for each configured bus
//  Read the addresses of all connected sensors

// a bus with no connected sensors should be notified

// connected sensors without a configuration entry should be notified
// For each sensor address
//  Search the configured sensors for the address
//  If an address does not have an entry in the configuration
//      report the unconfigured sensor

// configured sensors without a connected sensor should be notified

// if there are any configuration notices
//  they should be sent to the serial port
//  and the process should pause for 30 seconds


