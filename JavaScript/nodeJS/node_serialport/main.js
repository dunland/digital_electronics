const { SerialPort } = require('serialport')
const { MockBinding } = require('@serialport/binding-mock')

MockBinding.createPort('/dev/ROBOT', { echo: true, record: true })

const port = new SerialPort({
    binding: MockBinding,
    path: '/dev/ROBOT',
    baudRate: 14400
}, function (err) {
    if (err) {
        return console.log('Error: ', err.message)
    }
})

port.on('open', function (data) {
    console.log('pretend data from device')
})
port.on('data', function (data) {
    console.log('Data:', data)
})

console.log("hello");
