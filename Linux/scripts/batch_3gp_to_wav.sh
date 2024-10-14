for file in *.3gp; do
  output_file="${file%.3gp}.wav"
  ffmpeg -i "$file" -map_metadata 0 -c:v copy -c:a pcm_s16le "$output_file"
done

