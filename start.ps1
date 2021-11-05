$port= new-Object System.IO.Ports.SerialPort COM12,9500,None,8,one
$port.open()
$Age = Read-Host
$port.WriteLine("ciclos "+$Age)
do {
    $line = $port.ReadLine()
    Write-Host $line # Do stuff here
}
while ($port.IsOpen)
$port.Close()
$host.Exit()