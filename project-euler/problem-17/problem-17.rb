# assume 99 < n < 1000
def parseHundreds(n)
  m = (n / 100)
  @numberwords[m] + ' hundred'
end

# assume 0 < n < 100
def parseTensAndOnes(n)
  m = (n / 10) * 10
  if m >= 20
    output = @numberwords[m]
    output += '-' + @numberwords[n - m] unless n - m == 0
  else
    output = @numberwords[n]
  end
  output
end

@numberwords = {
  1 => 'one', 2 => 'two', 3 => 'three', 4 => 'four', 5 => 'five', 6 => 'six',
  7 => 'seven', 8 => 'eight', 9 => 'nine', 10 => 'ten', 11 => 'eleven',
  12 => 'twelve', 13 => 'thirteen', 14 => 'fourteen', 15 => 'fifteen',
  16 => 'sixteen', 17 => 'seventeen', 18 => 'eighteen', 19 => 'nineteen',
  20 => 'twenty', 30 => 'thirty', 40 => 'forty', 50 => 'fifty', 60 => 'sixty',
  70 => 'seventy', 80 => 'eighty', 90 => 'ninety'
}

sum = 0
(1..1000).each do |num|
  output = ''
  if num.to_s.size < 3
    output = parseTensAndOnes(num)
  elsif num.to_s.size == 3
    output = parseHundreds(num)
    tensandones = parseTensAndOnes(num - ((num / 100) * 100))
    output += " and #{tensandones}" unless !tensandones
  else
    output = 'one thousand'
  end
  sum += output.delete(' -').size
end
puts sum
